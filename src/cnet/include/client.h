#ifndef _CNET_CLIENT_H
#define _CNET_CLIENT_H

#include "./types.h"
#include "./socket.h"
#include "./bytes.h"
#include <memory>
#include <vector>
#include <thread>

namespace cnet
{
	class Client 
	{
	public:
		Client();
		~Client();

		bool Connect(const Address& address);
		void Close();
		bool Send(cnet::Bytes& data, cnet::Protocol proto = cnet::Protocol::TCP);

		const cnet::Address GetSockAddress() { return tcpSocket->GetSockAddress(); }
		const cnet::Address GetPeerAddress() { return tcpSocket->GetPeerAddress(); }

		OnReceiveEvent OnReceive;
		OnConnectedEvent OnConnected;
		OnDisconnectedEvent OnDisconnected;

	private:
		void TCPThread();
		void UDPThread();

		Address serverAddress;

		bool connected = false;

		std::shared_ptr<TCPSocket> tcpSocket;
		std::shared_ptr<UDPSocket> udpSocket;
		std::thread tcpThread;
		std::thread udpThread;
	};
}

#endif