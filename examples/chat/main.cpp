#include <cnet.h>
#include <stdio.h>
#include <cstring>
#include <iostream>

static void ServerOnReceive(void* server, cnet::Packet& packet)
{
	// Printing information that the server received something
	printf("INFO: Server received\n\t Bytes: %s\n\t Str: '%s'\n",
		packet.rawData.AsString().c_str(),
		packet.cleanData.ToString().c_str());
	// Resending the same packet to everyone besides the original sender
	((cnet::Server*)server)->SendAll(packet.cleanData, { packet.senderAddress });
}

static void ServerClientConnected(void* server, const cnet::Address address)
{
	// Printing the client that connected
	printf("INFO: Client connected (%s:%d)\n", address.ip.c_str(), address.port);
}

static void ServerClientDisconnected(void* server, const cnet::Address address)
{
	// Printing the client that disconnected
	printf("INFO: Client disconnected (%s:%d)\n", address.ip.c_str(), address.port);
}

static void ClientOnReceive(void* client, cnet::Packet& packet)
{
	// Printing the clean bytes (without the length) as string
	printf("%s\n",
		packet.cleanData.ToString().c_str());
}

int main(int argc, char** argv)
{
	// Asking the user whether to run as server or client
	std::string type;
	if (argc < 2)
	{
		printf("Please specify whether to use client or server: ");
		std::getline(std::cin, type);
		while (type.size() > 0 && isspace(type[0]))
			type.erase(type.begin());
	}
	else
		type = argv[1];

	// Initializing cnet
	cnet::Initialize();

	if (type == "client")
	{
		// Starting client
		cnet::Client client;
		// Asking for user's name
		std::string name;
		std::cout << "Enter your name:";
		std::getline(std::cin, name);

		std::string ip;
		std::cout << "Enter ip:";
		std::getline(std::cin, ip);

		// Connecting to server running at port 6565
		client.Connect({ ip, 6565});

		// Getting the server address
		const cnet::Address serverAddr = client.GetPeerAddress();

		printf("INFO: Connected to %s:%d\n", serverAddr.ip.c_str(), serverAddr.port);

		// Binding a function that gets called every packet that the client receives
		client.OnReceive = std::bind(ClientOnReceive, std::placeholders::_1, std::placeholders::_2);

		// Create an input loop
		while (true)
		{
			std::string input;
			std::cout << "";
			std::getline(std::cin, input);

			if (input == "exit")
				break;

			if (!input.empty())
			{
				// Sending the text prepended with [{name}] as bytes
				cnet::Bytes bytes = cnet::Bytes::FromString("[" + name + "]: " + input);

				// Checking whether the send was succsseful
				if (!client.Send(bytes))
				{
					// Closing if send wasn't successful
					printf("INFO: Server was closed probably, Exitting...");
					break;
				}
			}
		}
		client.Close();
	}
	else if (type == "server")
	{
		// Creating a server that will run on port 6565
		cnet::Server server(6565);

		// Binding the function to be called when packet is received in server
		server.OnReceive = std::bind(ServerOnReceive, std::placeholders::_1, std::placeholders::_2);
		// Binding the fucntion to be called when a new client is connected
		server.OnClientConnected = std::bind(ServerClientConnected, std::placeholders::_1, std::placeholders::_2);
		// Binding the fucntion to be called when a client disconnected
		server.OnClientDisconnected = std::bind(ServerClientDisconnected, std::placeholders::_1, std::placeholders::_2);

		// Getting the address that the server is running on
		const cnet::Address& addr = server.GetSockAddress();

		printf("INFO: Server started at '%s:%d'\n", addr.ip.c_str(), addr.port);

		// Start listening for connections and packets
		server.Run();

		// Wait untill server is closed
		while (server.IsRunning()) { std::this_thread::sleep_for(std::chrono::milliseconds(1)); };

		// Close the socket and cleanup
		server.Close();
	}
	else
	{
		printf("ERROR: Unknown type, please write 'server' or 'client'\n");
		return 1;
	}

	// Cleanup cnet
	cnet::Uninitialize();
	return 0;
}