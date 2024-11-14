#include "./../include/client.h"

namespace cnet
{
	Client::Client()
	{
		tcpSocket = std::shared_ptr<TCPSocket>(new TCPSocket());
		udpSocket = std::shared_ptr<UDPSocket>(new UDPSocket());
	}

	Client::~Client()
	{
		Close();
	}

	void Client::TCPThread()
	{
		while (connected)
		{
			cnet::Bytes lengthBuf = tcpSocket->Peek(4);

			std::uint32_t length;

			if (!lengthBuf.ToUint32(&length))
				continue;

			length += 4;

			cnet::Bytes tcpData = tcpSocket->Recv(length);

			while (tcpData.Size() < length)
				tcpData += tcpSocket->Recv(1);

			cnet::Packet dataTCP {
				tcpData.Slice(4),
				tcpData,
				tcpSocket->GetPeerAddress()
			};

			if (OnReceive) OnReceive(this, dataTCP);
		}
	}

	void Client::UDPThread()
	{
		while (connected)
		{
			cnet::Bytes lengthBuf = udpSocket->Peek(4);

			std::uint32_t length;

			if (!lengthBuf.ToUint32(&length))
				continue;

			length += 4;

			std::pair<cnet::Address, cnet::Bytes> data = udpSocket->RecvFrom(length);

			cnet::Packet dataUdp {
				data.second.Slice(4),
				data.second,
				data.first
			};

			if (OnReceive) OnReceive(this, dataUdp);
		}
	}

	bool Client::Send(cnet::Bytes& data, cnet::Protocol proto)
	{
		switch (proto)
		{
		case cnet::Protocol::TCP:
			return (tcpSocket->Send(cnet::Bytes::FromUint32((std::uint32_t)data.Size()) += data) == data.Size() + 4);
			break;
		case cnet::Protocol::UDP:
			return (udpSocket->SendTo(cnet::Bytes::FromUint32((std::uint32_t)data.Size()) += data, serverAddress) == data.Size() + 4);
			break;
		default:
			break;
		}
		return false;
	}

	void Client::Close()
	{
		connected = false;

		tcpSocket->Close();
		udpSocket->Close();

		if(tcpThread.joinable())
			tcpThread.join();
		if (udpThread.joinable())
			udpThread.join();

		if (OnDisconnected) OnDisconnected(this, serverAddress);
	}

	bool Client::Connect(const Address& address)
	{
		if (!tcpSocket->Connect(address))
			return false;

		if (!udpSocket->Bind(tcpSocket->GetSockAddress()))
			return false;

		connected = true;

		tcpThread = std::thread(&Client::TCPThread, this);
		udpThread = std::thread(&Client::UDPThread, this);

		serverAddress = tcpSocket->GetPeerAddress();

		if (OnConnected) OnConnected(this, serverAddress);

		return true;
	}
}