#ifndef _CNET_TYPES_H
#define _CNET_TYPES_H

#include <string>
#include <vector>
#include <cstdint>
#include <functional>
#include "./bytes.h"

namespace cnet 
{
	#if WIN32
	typedef std::uint64_t SocketHandle;
	#elif linux
	typedef int SocketHandle;
	#endif
	
	typedef std::uint8_t byte;

	enum Protocol
	{
		Unspecified = -1,
		TCP = 0,
		UDP = 1,
	};

	struct Address
	{
		std::string ip;
		unsigned short port;

		inline bool operator==(const Address& other) const {
			return port == other.port && ip == other.ip;
		}

	};

	struct Packet
	{
		cnet::Bytes cleanData;
		cnet::Bytes rawData;
		const Address senderAddress;
	};

	typedef std::function<void(void* const sender, cnet::Packet& packet)> OnReceiveEvent;
	typedef std::function<void(void* const sender, const Address address)> OnConnectedEvent;
	typedef std::function<void(void* const sender, const Address address)> OnDisconnectedEvent;

}

namespace std
{
	template<>
	struct hash<cnet::Address>
	{
		size_t operator()(const cnet::Address& addr) const noexcept
		{
			return std::hash<std::string>()(addr.ip) ^ std::hash<unsigned short>()(addr.port << 1);
		}
	};
}

#endif