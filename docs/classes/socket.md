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
 	<td><a href="socket/close">Close</a></td>
	<td>Closes the socket</td>
	<td>void</td>
</tr>
<tr>
 	<td><a href="socket/listen">Listen</a></td>
	<td>Start listening to new connections</td>
	<td>void</td>
</tr>
<tr>
 	<td><a href="socket/bind">Bind</a></td>
	<td>Binds the socket to the specified address</td>
	<td>bool</td>
</tr>
<tr>
 	<td><a href="socket/connect">Connect</a></td>
	<td>Connect to a server on the specified address</td>
	<td>bool</td>
</tr>
<tr>
 	<td><a href="socket/accept">Accept</a></td>
	<td>Accept a pending connection</td>
	<td>std::shared_ptr&lt;cnet::Socket&gt;</td>
</tr>
<tr>
 	<td><a href="socket/recv">Recv</a></td>
	<td>Receive the specified amount of bytes</td>
	<td>cnet::Bytes</td>
</tr>
<tr>
 	<td><a href="socket/recvfrom">RecvFrom</a></td>
	<td>Receive data from the socket</td>
	<td>std::pair&lt;cnet::Address, cnet::Bytes&gt;</td>
</tr>
<tr>
 	<td><a href="socket/peek">Peek</a></td>
	<td>Peek at the current data with the specified amount</td>
	<td>cnet::Bytes</td>
</tr>
<tr>
 	<td><a href="socket/send">Send</a></td>
	<td>Send data to the connected socket</td>
	<td>int</td>
</tr>
<tr>
 	<td><a href="socket/sendto">SendTo</a></td>
	<td>Send data to the specified address</td>
	<td>int</td>
</tr>
<tr>
 	<td><a href="socket/getpeeraddress">GetPeerAddress</a></td>
	<td>Returns the peer address of the socket</td>
	<td>cnet::Address</td>
</tr>
<tr>
 	<td><a href="socket/getsockaddress">GetSockAddress</a></td>
	<td>Returns the socket's address</td>
	<td>cnet::Address</td>
</tr>
<tr>
 	<td><a href="socket/gethandle">GetHandle</a></td>
	<td>Returns the socket's native handle</td>
	<td>cnet::SocketHandle</td>
</tr>
</table>

### See also
- [SocketHandle](./../types/sockethandle.md)
- [Address](./../types/address.md)
- [Bytes](./../classes/bytes.md)