#include "./../include/server.h"

#include <algorithm>

namespace cnet
{
	Server::Server(unsigned short port)
	{
		tcpSocket = std::shared_ptr<TCPSocket>(new TCPSocket());
		udpSocket = std::shared_ptr<UDPSocket>(new UDPSocket());
		tcpSocket->Bind({ "0.0.0.0", port });
		udpSocket->Bind({ "0.0.0.0", port });
	}

	Server::~Server() { Close(); }

	bool Server::IsRunning() { return running; }

	void Server::Run()
	{
		running = true;
		tcpSocket->Listen();
		tcpThread = std::thread(&Server::TCPThread, this);
		udpThread = std::thread(&Server::UDPThread, this);
	}

	void Server::Close()
	{
		running = false;

		addressToClient.clear();
		clients.clear();

		tcpSocket->Close();
		udpSocket->Close();

		tcpThread.join();
		udpThread.join();
	}

	void Server::CloseClient(const Address &address)
	{
		if (IsClientConnected(address))
		{
			if (addressToClient[address].get() != NULL)
				addressToClient[address]->Close();
			addressToClient.erase(address);
			clients.erase(std::find(clients.begin(), clients.end(), address));
			if (OnClientDisconnected) OnClientDisconnected(this, address);
		}
	}

	bool Server::SendAll(cnet::Bytes& data, const std::vector<Address>& exceptions, cnet::Protocol proto)
	{
		std::vector<Address> lClients = GetClients();
		for (size_t i = 0; i < lClients.size(); i++)
		{
			if (std::find(exceptions.begin(), exceptions.end(), lClients[i]) == exceptions.end())
				if (!Send(data, lClients[i], proto))
					return false;
		}
		return true;
	}

	bool Server::Send(cnet::Bytes& data, const Address &address, cnet::Protocol proto)
	{
		switch (proto)
		{
		case cnet::Protocol::TCP:
			if (IsClientConnected(address))
				return (addressToClient[address]->Send(cnet::Bytes::FromUint32((std::uint32_t)data.Size()) += data) == data.Size() + 4);
			break;
		case cnet::Protocol::UDP:
			return (udpSocket->SendTo(cnet::Bytes::FromUint32((std::uint32_t)data.Size()) += data, address) == data.Size() + 4);
			break;
		default:
			break;
		}
		return false;
	}

	bool Server::IsClientConnected(const cnet::Address &address)
	{
		return addressToClient.find(address) != addressToClient.end();
	}
	void Server::TCPThread()
	{
		while (running)
		{
			std::shared_ptr<cnet::Socket> soc = tcpSocket->Accept();
			if (!soc)
				continue;
			const Address addr = soc->GetPeerAddress();
			addressToClient[addr] = soc;
			clients.push_back(addr);
			if (OnClientConnected) OnClientConnected(this, addr);
			std::thread thread(&Server::ClientThread, this, soc);
			thread.detach();
		}
	}

	void Server::ClientThread(std::shared_ptr<cnet::Socket> client)
	{
		while (running && addressToClient.find(client->GetPeerAddress()) != addressToClient.end())
		{
			cnet::Bytes lengthBuf = client->Recv(4);

			std::uint32_t length = 0;

			if (!lengthBuf.ToUint32(&length)) 
			{
				CloseClient(client->GetPeerAddress());
				break;
			}

			cnet::Bytes tcpData = client->Recv(length);

			while (tcpData.Size() < length)
				tcpData += client->Recv(1);

			tcpData = lengthBuf + tcpData;

			cnet::Packet dataTCP {
				tcpData.Slice(4),
				tcpData,
				client->GetPeerAddress()
			};

			if(OnReceive) OnReceive(this, dataTCP);
		}
	}

	void Server::UDPThread()
	{
		while (running)
		{
			cnet::Bytes lengthBuf = udpSocket->Peek(4);

			std::uint32_t length = 0;

			if (!lengthBuf.ToUint32(&length))
				continue;

			length += 4;
			
			std::pair<cnet::Address, cnet::Bytes> data = udpSocket->RecvFrom(length);

			if (addressToClient.find(data.first) != addressToClient.end())
			{
				cnet::Packet dataUdp {
					data.second.Slice(4),
					data.second,
					data.first
				};

				if(OnReceive) OnReceive(this, dataUdp);
			}
		}
	}
}