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

<table>
<tr>
    <th>Name</th>
    <th>Description</th>
    <th>Return type</th>
</tr>
<tr>
 	<td><a href="server/run.md">Run</a></td>
	<td>Starts the server</td>
	<td>void</td>
</tr>
<tr>
 	<td><a href="server/isrunning.md">IsRunning</a></td>
	<td>Returns whether the server is running</td>
	<td>bool</td>
</tr>
<tr>
 	<td><a href="server/close.md">Close</a></td>
	<td>Closes the server and cleans up</td>
	<td>void</td>
</tr>
<tr>
 	<td><a href="server/closeclient.md">CloseClient</a></td>
	<td>Closes the client with the specified address</td>
	<td>void</td>
</tr>
<tr>
 	<td><a href="server/sendall.md">SendAll</a></td>
	<td>Send data to all connected clients</td>
	<td>bool</td>
</tr>
<tr>
 	<td><a href="server/send.md">Send</a></td>
	<td>Send data to a specific client</td>
	<td>bool</td>
</tr>
<tr>
 	<td><a href="server/isclientconnected.md">IsClientConnected</a></td>
	<td>Returns whether a specific client is connected</td>
	<td>bool</td>
</tr>
<tr>
 	<td><a href="server/getpeeraddress.md">GetPeerAddress</a></td>
	<td>Returns the peer address of the server</td>
	<td>cnet::Address</td>
</tr>
<tr>
 	<td><a href="server/getsockaddress.md">GetSockAddress</a></td>
	<td>Returns the server's address</td>
	<td>cnet::Address</td>
</tr>
<tr>
 	<td><a href="server/getclients.md">GetClients</a></td>
	<td>Returns a vector containing all the clients addresses</td>
	<td>std::vector&lt;cnet::Address&gt;</td>
</tr>
</table>

### See also
- [UPDSocket](./udpsocket.md)
- [TCPSocket](./tcpsocket.md)
- [Socket](./socket.md)
- [Address](./../types/address.md)