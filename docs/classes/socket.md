# cnet::Socket

**cnet::Socket** is a wrapper around the native socket implementation of each os

```C++
class Socket
{
public:
	Socket(int type, int protocol);
	~Socket();
private:
	cnet::SocketHandle socketId;
	cnet::Address peerAddress;
	cnet::Address sockAddress;
	int type;
	int protocol;
};
```

### Methods
| Name  |  Description | Return type |
|-------|--------------|-------------|
|[Close](socket/close.md)|Closes the socket|void|
|[Listen](socket/listen.md)|Start listening to new connections|void|
|[Bind](socket/bind.md)|Binds the socket to the specified address|bool|
|[Connect](socket/connect.md)|Connect to a server on the specified address|bool|
|[Accept](socket/accept.md)|Accept a pending connection|std::shared_ptr\<cnet::Socket\>|
|[Recv](socket/recv.md)|Receive the specified amount of bytes|[cnet::Bytes](./bytes.md)|
|[Peek](socket/peek.md)|Peek at the current data with the specified amount|[cnet::Bytes](./bytes.md)|
|[RecvFrom](socket/recvfrom.md)|Receive data from the socket|std::pair<[cnet::Address](./../types/address.md), [cnet::Bytes](./bytes.md)>|
|[Send](socket/send.md)|Send data to the connected socket|int|
|[SendTo](socket/sendto.md)|Send data to the specified address|int|
|[GetPeerAddress](socket/getpeeraddress.md)|Returns the peer address of the socket|[cnet::Address](./../types/address.md)|
|[GetSockAddress](socket/getsockaddress.md)|Returns the socket's address|[cnet::Address](./../types/address.md)|
|[GetHandle](socket/gethandle.md)|Returns the socket's native handle|[cnet::SocketHandle](./../types/sockethandle.md)|

### See also
- [SocketHandle](./../types/sockethandle.md)
- [Address](./../types/address.md)