# cnet::UDPSocket

**UDPSocket** has the same methods as [Socket](socket.md), the only difference is that it initializes a udp socket by itself.

```C++
class UDPSocket : public Socket
{
public:
	UDPSocket() : Socket(SOCK_DGRAM, IPPROTO_UDP) {}
};
```