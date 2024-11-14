### Send method of cnet::Server

The **Send** method sends data to the specified address
### Syntax
```C++
bool Send(
    cnet::Bytes& data, 
    const Address &address, 
    cnet::Protocol proto = cnet::Protocol::TCP);
```
### Parameters
`data` 

The data to send

`address`

The address of the client

`proto`

Which protocol to use. the default is **cnet::Protocol::TCP**

### Return value
`true` - all data was sent
`false` - not all data was sent