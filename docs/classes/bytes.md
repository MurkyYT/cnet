# cnet::Bytes

**cnet::Bytes** is a wrapper around std::vector<[cnet::Byte](./../types/byte.md)> with a lot of useful [methods](#methods)

```C++
class Bytes
{
private:
	std::vector<cnet::byte> data;
};
```

### Methods
| Name  |  Description | Return type |
|-------|--------------|-------------|
|[Size](bytes/size.md)|Returns the size of the data|std::size_t|
|[ToInt64](bytes/toint64.md)|Converts the 8 first bytes starting from startIndex to int64|bool|
|[ToUint64](bytes/touint64.md)|Same as ToInt64 but unsigned|bool|
|[ToInt32](bytes/toint32.md)|Converts the 4 first bytes starting from startIndex to int32|bool|
|[ToUint32](bytes/touint32.md)|Same as ToInt32 but unsigned|bool|
|[AsString](bytes/asstring.md)|Returns the string representation of the bytes (e.g "[0xFF,0xFF]")|std::string|
|[ToString](bytes/tostring.md)|Converts the bytes to a string|std::string|
|[Slice](bytes/slice.md)|Returns a new instance of cnet::Bytes which is a slice of the current object|cnet::Bytes|
|[FromInt64](bytes/fromint64.md)|Converts int64_t to cnet::Bytes|cnet::Bytes|
|[FromUint64](bytes/fromuint64.md)|Converts uint64_t to cnet::Bytes|cnet::Bytes|
|[FromInt32](bytes/fromint32.md)|Converts int32_t to cnet::Bytes|cnet::Bytes|
|[FromUint32](bytes/fromuint32.md)|Converts uint32_t to cnet::Bytes|cnet::Bytes|
|[FromString](bytes/fromstring.md)|Converts std::string to cnet::Bytes|cnet::Bytes|