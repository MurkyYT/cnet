### Slice method of cnet::Bytes

The **Slice** method creates a new instace of cnet::Bytes that is a slice from the current object

### Syntax
```C++
cnet::Bytes Slice(
    size_t from, 
    size_t to = SliceOptions::End
);
```
### Parameters
`from`

Specifies the index from where to start slicing, should be greater then 0 and smaller then [Size()](size.md)

`to`

Specifies the index of the last byte, should be greater then *from*. Default value is **SliceOptions::End** (-1)

### Return value
A new `cnet::Bytes` object