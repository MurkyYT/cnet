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

<table>
<tr>
    <th>Name</th>
    <th>Description</th>
    <th>Return type</th>
</tr>
<tr>
 	<td><a href="client/connect.md">Connect</a></td>
	<td>Connects to the specified address</td>
	<td>bool</td>
</tr>
<tr>
 	<td><a href="client/close.md">Close</a></td>
	<td>Closes the client and cleans up</td>
	<td>void</td>
</tr>
<tr>
 	<td><a href="client/send.md">Send</a></td>
	<td>Send data to the server</td>
	<td>bool</td>
</tr>
<tr>
 	<td><a href="client/getpeeraddress.md">GetPeerAddress</a></td>
	<td>Returns the peer address of the client</td>
	<td>cnet::Address</td>
</tr>
<tr>
 	<td><a href="client/getsockaddress.md">GetSockAddress</a></td>
	<td>Returns the client's address</td>
	<td>cnet::Address</td>
</tr>
</table>


### See also
- [UPDSocket](./udpsocket.md)
- [TCPSocket](./tcpsocket.md)
- [Address](./../types/address.md)