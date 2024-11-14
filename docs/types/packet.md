# Packet (struct)
```C++
struct Packet
{
	cnet::Bytes cleanData;
	cnet::Bytes rawData;
	const Address senderAddress;
};
```
Member types:
- [Address](./address.md)
- [Bytes](./../classes/bytes.md)