### IsClientConnected method of cnet::Server

The **IsClientConnected** method returns whether this address is a connected client
### Syntax
```C++
bool IsClientConnected(
    const cnet::Address &address
);
```

### Parameters

`address`

The address of the client

### Return value
`false` - the address is not a connected client
`true` - the address is a connected client