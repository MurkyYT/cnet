### SendAll method of cnet::Server

The **SendAll** method sends data to all the clients
### Syntax
```C++
bool SendAll(
    cnet::Bytes& data, 
    const std::vector<Address>& exceptions = {}, 
    cnet::Protocol proto = cnet::Protocol::TCP
);
```
### Parameters
`data` 

The data to send

`exceptions`

Which addresses not to send to

`proto`

Which protocol to use. the default is **cnet::Protocol::TCP**

### Return value
`true` - all data was sent
`false` - not all data was sent