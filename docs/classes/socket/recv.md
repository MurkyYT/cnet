### Recv method of cnet::Socket

The **Recv** methods reads data from a socket

### Syntax
```C++
cnet::Bytes Recv(
    int amount
);
```

### Parameters

`amount`

The max amount of bytes to read

### Return value

`cnet::Bytes` containing the read data

### See also
- [cnet::Bytes](./../bytes.md)