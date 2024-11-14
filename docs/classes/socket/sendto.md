### SendTo method of cnet::Socket

The **SendTo** methods sends data thru the socket to a specific address

### Syntax
```C++
int SendTo(
    const cnet::Bytes& data,
    const Address& to
);
```

### Parameters

`data`

The data to send

`to`

The address to send to

### Return value

The amount of data sent