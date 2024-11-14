### FromUint32 method of cnet::Bytes

The **FromUint32** method std::uint32_t to cnet::Bytes

### Syntax
```C++
static Bytes FromUint32(
    std::uint32_t value, 
    bool bigEndian = true
);
```

### Parameters
`value`

The value which to convert

`bigEndian` 

Specifies whether the data will be saved in big endianness or small endianness

### Return value
`cnet::Bytes` that contains the value as bytes