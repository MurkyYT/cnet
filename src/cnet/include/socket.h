#ifndef _CNET_SOCKET_H
#define _CNET_SOCKET_H

#include "types.h"
#include "bytes.h"
#include <memory>
#include <vector>
#include <stdexcept>

#if WIN32
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <windows.h>
#elif linux
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#endif

namespace cnet
{
	class Socket
	{
	public:
		Socket(int type, int protocol);
		~Socket();

		void Close();
		void Listen();
		bool Bind(const Address& address);
		bool Connect(const Address& address);
		std::shared_ptr<Socket> Accept();
		cnet::Bytes Recv(int amount);
		cnet::Bytes Peek(int amount);
		std::pair<Address, cnet::Bytes> RecvFrom(int amount);
		int Send(const cnet::Bytes& data);
		int SendTo(const cnet::Bytes& data, const Address& to);
		const Address GetPeerAddress();
		const Address GetSockAddress();
		const SocketHandle GetHandle() { return socketId; }

	private:
		Socket(SocketHandle socketId, int type, int protocol);
		SocketHandle socketId;
		Address peerAddress;
		Address sockAddress;
		int type;
		int protocol;
	};

	class TCPSocket : public Socket
	{
	public:
		TCPSocket() : Socket(SOCK_STREAM, IPPROTO_TCP) {}
	};

	class UDPSocket : public Socket
	{
	public:
		UDPSocket() : Socket(SOCK_DGRAM, IPPROTO_UDP) {}
	};
};

#endif