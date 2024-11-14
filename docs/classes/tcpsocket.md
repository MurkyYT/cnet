# cnet::TCPSocket

**TCPSocket** has the same methods as [Socket](socket.md), the only difference is that it initializes a tcp socket by itself.

```C++
class TCPSocket : public Socket
{
public:
	TCPSocket() : Socket(SOCK_STREAM, IPPROTO_TCP) {}
};
```