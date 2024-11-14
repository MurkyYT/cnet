### Send method of cnet::Client

The **Send** method sends data to the server
### Syntax
```C++
bool Send(
    cnet::Bytes& data, 
    cnet::Protocol proto = cnet::Protocol::TCP
);
```
### Parameters
`data` 

The data to send

`proto`

Which protocol to use. the default is **cnet::Protocol::TCP**

### Return value
`true` - all data was sent
`false` - not all data was sent