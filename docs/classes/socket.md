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

<table>
<tr>
    <th>Name</th>
    <th>Description</th>
    <th>Return type</th>
</tr>
<tr>
 	<td><a href="socket/close.md">Close</a></td>
	<td>Closes the socket</td>
	<td>void</td>
</tr>
<tr>
 	<td><a href="socket/listen.md">Listen</a></td>
	<td>Start listening to new connections</td>
	<td>void</td>
</tr>
<tr>
 	<td><a href="socket/bind.md">Bind</a></td>
	<td>Binds the socket to the specified address</td>
	<td>bool</td>
</tr>
<tr>
 	<td><a href="socket/connect.md">Connect</a></td>
	<td>Connect to a server on the specified address</td>
	<td>bool</td>
</tr>
<tr>
 	<td><a href="socket/accept.md">Accept</a></td>
	<td>Accept a pending connection</td>
	<td>std::shared_ptr&lt;cnet::Socket&gt;</td>
</tr>
<tr>
 	<td><a href="socket/recv.md">Recv</a></td>
	<td>Receive the specified amount of bytes</td>
	<td>cnet::Bytes</td>
</tr>
<tr>
 	<td><a href="socket/recvfrom.md">RecvFrom</a></td>
	<td>Receive data from the socket</td>
	<td>std::pair&lt;cnet::Address, cnet::Bytes&gt;</td>
</tr>
<tr>
 	<td><a href="socket/peek.md">Peek</a></td>
	<td>Peek at the current data with the specified amount</td>
	<td>cnet::Bytes</td>
</tr>
<tr>
 	<td><a href="socket/send.md">Send</a></td>
	<td>Send data to the connected socket</td>
	<td>int</td>
</tr>
<tr>
 	<td><a href="socket/sendto.md">SendTo</a></td>
	<td>Send data to the specified address</td>
	<td>int</td>
</tr>
<tr>
 	<td><a href="socket/getpeeraddress.md">GetPeerAddress</a></td>
	<td>Returns the peer address of the socket</td>
	<td>cnet::Address</td>
</tr>
<tr>
 	<td><a href="socket/getsockaddress.md">GetSockAddress</a></td>
	<td>Returns the socket's address</td>
	<td>cnet::Address</td>
</tr>
<tr>
 	<td><a href="socket/gethandle.md">GetHandle</a></td>
	<td>Returns the socket's native handle</td>
	<td>cnet::SocketHandle</td>
</tr>
</table>

### See also
- [SocketHandle](./../types/sockethandle.md)
- [Address](./../types/address.md)
- [Bytes](./../classes/bytes.md)