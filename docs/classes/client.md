# cnet::Client

**cnet::Client** is a threaded async udp and tcp communication client implemented for you

```C++
class Client 
{
public:
    OnReceiveEvent OnReceive;
    OnConnectedEvent OnConnected;
    OnDisconnectedEvent OnDisconnected;

private:
    Address serverAddress;

    bool connected = false;

    std::shared_ptr<TCPSocket> tcpSocket;
    std::shared_ptr<UDPSocket> udpSocket;
    std::thread tcpThread;
    std::thread udpThread;
};
```

### Methods
| Name  |  Description | Return type |
|-------|--------------|-------------|
|[Connect](./client/connect.md)|Connects to the specified address|bool|
|[Close](./client/close.md)|Closes the client and cleans up|void|
|[Send](./client/send.md)|Send data to the server|bool|
|[GetPeerAddress](./client/getpeeraddress.md)|Returns the peer address of the client|[cnet::Address](./../types/address.md)|
|[GetSockAddress](./client/getsockaddress.md)|Returns the client's address|[cnet::Address](./../types/address.md)|


### See also
- [UPDSocket](./udpsocket.md)
- [TCPSocket](./tcpsocket.md)
- [Address](./../types/address.md)