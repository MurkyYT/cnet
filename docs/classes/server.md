# cnet::Server

**cnet::Server** is a threaded async udp and tcp communication server implemented for you

```C++
class Server
{
public:
    OnReceiveEvent OnReceive;
    OnConnectedEvent OnClientConnected;
    OnDisconnectedEvent OnClientDisconnected;

private:
    std::vector<Address> clients;
    std::unordered_map<Address, std::shared_ptr<Socket>> addressToClient;

    bool running = false;

    std::shared_ptr<TCPSocket> tcpSocket;
    std::shared_ptr<UDPSocket> udpSocket;
    std::thread tcpThread;
    std::thread udpThread;
};
```

### Methods
| Name  |  Description | Return type |
|-------|--------------|-------------|
|[Run](./server/run.md)|Starts the server|void|
|[IsRunning](./server/isrunning.md)|Returns whether the server is running|bool|
|[Close](./server/close.md)|Closes the server and cleans up|void|
|[CloseClient](./server/closeclient.md)|Closes the client with the specified address|void|
|[SendAll](./server/sendall.md)|Send data to all connected clients|bool|
|[Send](./server/send.md)|Send data to a specific client|bool|
|[IsClientConnected](./server/isclientconnected.md)|Returns whether a specific client is connected|bool|
|[GetPeerAddress](./server/getpeeraddress.md)|Returns the peer address of the server|[cnet::Address](./../types/address.md)|
|[GetSockAddress](./server/getsockaddress.md)|Returns the server's address|[cnet::Address](./../types/address.md)|
|[GetClients](./server/getclients.md)|Returns a vector containing all the clients addresses|std::vector<[cnet::Address](./../types/address.md)>|

### See also
- [UPDSocket](./udpsocket.md)
- [TCPSocket](./tcpsocket.md)
- [Socket](./socket.md)
- [Address](./../types/address.md)