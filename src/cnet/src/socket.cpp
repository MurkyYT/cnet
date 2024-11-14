#include "./../include/socket.h"

#if WIN32
#undef INVALID_SOCKET
#undef SOCKET_ERROR
#define SIZEOFSOCKADDR int
#elif linux
#define SIZEOFSOCKADDR unsigned int
#endif

#define INVALID_SOCKET (~0)
#define SOCKET_ERROR -1

namespace cnet
{
	Socket::Socket(int type, int protocol)
		: type(type), protocol(protocol)
	{
		socketId = socket(AF_INET, type, protocol);
		if (socketId == INVALID_SOCKET)
			throw std::runtime_error("Couldn't create socket");
	}

	Socket::Socket(SocketHandle socketId, int type, int protocol)
		: type(type), protocol(protocol), socketId(socketId)
	{
	}

	Socket::~Socket()
	{
		Close();
	}

	bool Socket::Bind(const Address& address)
	{
		sockaddr_in service;
		service.sin_family = AF_INET;
		service.sin_port = htons(address.port);
		inet_pton(AF_INET, address.ip.c_str(), &service.sin_addr.s_addr);

		return bind(socketId, (sockaddr*)&service, sizeof(service)) != SOCKET_ERROR;
	}

	void Socket::Close()
	{
#if WIN32
		int shtd = shutdown(socketId, SD_BOTH);
		int cls = closesocket(socketId);
#elif linux
		shutdown(socketId, SHUT_RDWR);
		close(socketId);
#endif
	}

	void Socket::Listen()
	{
		if (listen(socketId, 1) == SOCKET_ERROR)
		{
			Close();
			throw std::runtime_error("Couldn't listen with socket");
		}
	}

	bool Socket::Connect(const Address& address)
	{
		sockaddr_in service;
		service.sin_family = AF_INET;
		service.sin_port = htons(address.port);
		inet_pton(AF_INET, address.ip.c_str(), &service.sin_addr.s_addr);

		return connect(socketId, (sockaddr*)&service, sizeof(service)) != SOCKET_ERROR;
	}

	const Address Socket::GetPeerAddress()
	{
		if (peerAddress.ip.empty()) {
			struct sockaddr_in addr;
			addr.sin_family = AF_INET;
			SIZEOFSOCKADDR len = sizeof(addr);
			char buf[1024];
			getpeername(socketId, (sockaddr*)&addr, &len);
			inet_ntop(AF_INET, &addr.sin_addr, buf, 1024);

			peerAddress = { buf,ntohs(addr.sin_port) };
		}
		return peerAddress;
	}

	const Address Socket::GetSockAddress()
	{
		if (sockAddress.ip.empty()) {
			struct sockaddr_in addr;
			addr.sin_family = AF_INET;
			SIZEOFSOCKADDR len = sizeof(addr);
			char buf[1024];
			getsockname(socketId, (sockaddr*)&addr, &len);
			inet_ntop(AF_INET, &addr.sin_addr, buf, 1024);

			sockAddress = { buf,ntohs(addr.sin_port) };
		}
		return sockAddress;
	}

	std::shared_ptr<Socket> Socket::Accept()
	{
		struct sockaddr_in addr;
		SIZEOFSOCKADDR len = sizeof(addr);
		char buf[1024];
		SocketHandle connected = accept(socketId, (sockaddr *)&addr, &len);
		if (connected == INVALID_SOCKET)
		{
			Close();
			return NULL;
		}
		inet_ntop(AF_INET, &addr.sin_addr, buf, 1024);
		Socket *socket = new Socket(connected, type, protocol);

		return std::shared_ptr<Socket>(socket);
	}

	cnet::Bytes Socket::Recv(int amount)
	{
		std::vector<cnet::byte> result;
		result.resize(amount);
		int newSize = recv(socketId, (char *)result.data(), amount, 0);
		if (newSize == -1)
			result.resize(0);
		else
			result.resize(newSize);
		return cnet::Bytes(result);
	}

	std::pair<Address, cnet::Bytes> Socket::RecvFrom(int amount)
	{
		std::vector<cnet::byte> result;
		result.resize(amount);
		sockaddr_in from;
		SIZEOFSOCKADDR sizeOfFrom = sizeof(from);
		int res = recvfrom(socketId, (char *)result.data(), amount, 0, (sockaddr *)&from, &sizeOfFrom);

		char buf[1024];
		inet_ntop(AF_INET, &from.sin_addr, buf, 1024);
		Address sender{buf, htons(from.sin_port)};

		return std::make_pair(sender, cnet::Bytes(result));
	}

	cnet::Bytes Socket::Peek(int amount)
	{
		std::vector<cnet::byte> result;
		result.resize(amount);
		int read = recvfrom(socketId, (char*)result.data(), amount, MSG_PEEK, NULL, NULL);

#if WIN32
		if (read == -1 && WSAGetLastError() != WSAEMSGSIZE)
			result.resize(0);
#else
		if (read == -1)
			result.resize(0);
#endif

		return cnet::Bytes(result);
	}

	int Socket::Send(const cnet::Bytes& bytes)
	{
#if WIN32
		return send(socketId, (char*)bytes.data.data(), (int)bytes.data.size(), NULL);
#else
		return send(socketId, (char*)bytes.data.data(), (int)bytes.data.size(), MSG_NOSIGNAL);
#endif
	}
	int Socket::SendTo(const cnet::Bytes& bytes, const Address &to)
	{
		sockaddr_in toSocaddr;
		SIZEOFSOCKADDR sizeOfTo = sizeof(toSocaddr);
		toSocaddr.sin_port = htons(to.port);
		toSocaddr.sin_family = AF_INET;
		inet_pton(AF_INET, to.ip.c_str(), &toSocaddr.sin_addr.s_addr);

#if WIN32
		return sendto(socketId, (char*)bytes.data.data(), (int)bytes.data.size(), NULL, (sockaddr*)&toSocaddr, sizeOfTo);
#else
		return sendto(socketId, (char*)bytes.data.data(), (int)bytes.data.size(), MSG_NOSIGNAL, (sockaddr*)&toSocaddr, sizeOfTo);
#endif
	}
}