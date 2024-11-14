### ToInt32 method of cnet::Bytes

The **ToInt32** method converts the 8 first bytes (starting from startIndex) to int32

### Syntax
```C++
bool ToInt32(
    std::int32_t* out,
    size_t startIndex = 0, 
    bool bigEndian = true
);
```

### Parameters
`out` 

Pointer to where to save the data. Can't be **nullptr** 

`startIndex` 

Specifies the index from where to start converting, should be greater then 0 and smaller then [Size()](size.md) - 4

`bigEndian`

Specifies whether the data is stored in big endianness or small endianness

### Return value
`false` - the conversion failed
`true` - the conversion was successful