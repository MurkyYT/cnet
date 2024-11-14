### RecvFrom method of cnet::Socket

The **RecvFrom** methods reads data from a socket

### Syntax
```C++
std::pair<Address, cnet::Bytes> RecvFrom(
    int amount
);
```

### Parameters

`amount`

The max amount of bytes to read

### Return value

`std::pair<Address, cnet::Bytes>` containing the read data and the address that it was read from