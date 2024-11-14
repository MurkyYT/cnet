<center>

[![cnet Logo](logo/cNetLogo.png)](https://murkyyt.github.io/cnet)
***cnet*** is a small library written in C++ to ease the use of sockets in cross-platform use cases.

</center>

## Features
- Cross-platform code usage, same code for different platforms (Linux and Windows)
- Base [Socket](docs/classes/socket.md) class for custom socket creation
- Classes for [TCPSocket](docs/classes/tcpsocket.md) and [UDPSocket](docs/classes/udpsocket.md)
- Built-in [Server](docs/classes/server.md) and [Client]((docs/classes/client.md)) classes for threaded async `TCP` and `UDP` simultaneous communications

## Docs

- #### Primitive Types
    - [SocketHandle](docs/types/sockethandle.md)
    - [Protocol](docs/types/protocol.md)
    - [Byte](docs/types/byte.md)
    - [Address](docs/types/address.md)
    - [Packet](docs/types/packet.md)

- #### Classes
    - [Bytes](docs/classes/bytes.md)
    - [Instance](docs/classes/instance.md)
    - [Socket](docs/classes/socket.md)
    - [Server](docs/classes/server.md)
    - [Client](docs/classes/client.md)

## Examples

- [Simple chat](src/examples/chat/README.md)