#include "./../../include/instance.h"

#include <WinSock2.h>
#include <windows.h>
#include <stdexcept>

namespace cnet
{
	void Initialize()
	{
		WSADATA wsaData;
		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != ERROR_SUCCESS)
			throw std::runtime_error("Couldn't initialize WSA");
	}

	void Uninitialize()
	{
		WSACleanup();
	}
}