#ifndef _CNET_SERVER_H
#define _CNET_SERVER_H

#include "./types.h"
#include "./socket.h"
#include "./bytes.h"
#include <memory>
#include <vector>
#include <thread>
#include <unordered_map>

namespace cnet 
{
	class Server
	{
	public:
		Server(unsigned short port);
		~Server();

		void Run();
		bool IsRunning();
		void Close();
		void CloseClient(const Address& address);
		bool SendAll(cnet::Bytes& data, const std::vector<Address>& exceptions = {}, cnet::Protocol proto = cnet::Protocol::TCP);
		bool Send(cnet::Bytes& data, const Address &address, cnet::Protocol proto = cnet::Protocol::TCP);
        bool IsClientConnected(const cnet::Address &address);

        const cnet::Address GetSockAddress() { return tcpSocket->GetSockAddress(); }
		const cnet::Address GetPeerAddress() { return tcpSocket->GetPeerAddress(); }

		std::vector<cnet::Address> GetClients() { return clients; }

		OnReceiveEvent OnReceive;
		OnConnectedEvent OnClientConnected;
		OnDisconnectedEvent OnClientDisconnected;

	private:
		void TCPThread();
		void UDPThread();
		void ClientThread(std::shared_ptr<cnet::Socket> client);

		std::vector<Address> clients;
		std::unordered_map<Address, std::shared_ptr<Socket>> addressToClient;

		bool running = false;

		std::shared_ptr<TCPSocket> tcpSocket;
		std::shared_ptr<UDPSocket> udpSocket;
		std::thread tcpThread;
		std::thread udpThread;
	};
}

#endif