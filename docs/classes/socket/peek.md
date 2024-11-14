### Peek method of cnet::Socket

The **Peek** methods peeks data from a socket

### Syntax
```C++
cnet::Bytes Peek(
    int amount
);
```

### Parameters

`amount`

The max amount of bytes to peek at

### Return value

[`cnet::Bytes`](./../bytes.md) containing the peeked data