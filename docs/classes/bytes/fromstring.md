### FromString method of cnet::Bytes

The **FromString** method std::string to cnet::Bytes

### Syntax
```C++
static Bytes FromString(
    std::string value, 
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