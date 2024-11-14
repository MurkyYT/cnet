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

<table>
<tr>
    <th>Name</th>
    <th>Description</th>
    <th>Return type</th>
</tr>
<tr>
 	<td><a href="bytes/size">Size</a></td>
	<td>Returns the size of the data</td>
	<td>std::size_t</td>
</tr>
<tr>
 	<td><a href="bytes/toint64">ToInt64</a></td>
	<td>Converts the 8 first bytes starting from startIndex to int64</td>
	<td>bool</td>
</tr>
<tr>
 	<td><a href="bytes/touint64">ToUint64</a></td>
	<td>Same as ToInt64 but unsigned</td>
	<td>bool</td>
</tr>
<tr>
 	<td><a href="bytes/toint32">ToInt32</a></td>
	<td>Converts the 4 first bytes starting from startIndex to int32</td>
	<td>bool</td>
</tr>
<tr>
 	<td><a href="bytes/touint32">ToUint32</a></td>
	<td>Same as ToInt32 but unsigned</td>
	<td>bool</td>
</tr>
<tr>
 	<td><a href="bytes/asstring">AsString</a></td>
	<td>Returns the string representation of the bytes (e.g "[0xFF,0xFF]")</td>
	<td>std::string</td>
</tr>
<tr>
 	<td><a href="bytes/tostring">ToString</a></td>
	<td>Converts the bytes to a string</td>
	<td>std::string</td>
</tr>
<tr>
 	<td><a href="bytes/slice">Slice</a></td>
	<td>Returns a new instance of cnet::Bytes which is a slice of the current object</td>
	<td>cnet::Bytes</td>
</tr>
<tr>
 	<td><a href="bytes/fromint64">FromInt64</a></td>
	<td>Converts int64_t to cnet::Bytes</td>
	<td>cnet::Bytes</td>
</tr>
<tr>
 	<td><a href="bytes/fromuint64">FromUint64</a></td>
	<td>Converts uint64_t to cnet::Bytes</td>
	<td>cnet::Bytes</td>
</tr>
<tr>
 	<td><a href="bytes/fromint32">FromInt32</a></td>
	<td>Converts int32_t to cnet::Bytes</td>
	<td>cnet::Bytes</td>
</tr>
<tr>
 	<td><a href="bytes/fromuint32">FromUint32</a></td>
	<td>Converts uint32_t to cnet::Bytes</td>
	<td>cnet::Bytes</td>
</tr>
<tr>
 	<td><a href="bytes/fromstring">FromString</a></td>
	<td>Converts std::string to cnet::Bytes</td>
	<td>cnet::Bytes</td>
</tr>
</table>