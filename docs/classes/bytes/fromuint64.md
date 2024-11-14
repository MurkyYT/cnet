### FromUint64 method of cnet::Bytes

The **FromUint64** method std::uint64_t to cnet::Bytes

### Syntax
```C++
static Bytes FromUint64(
    std::uint64_t value, 
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