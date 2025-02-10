#include "./../include/bytes.h"
#include <stdexcept>
#include <cinttypes>

namespace cnet
{
	Bytes Bytes::FromInt64(std::int64_t value, bool bigEndian)
	{
		cnet::Bytes res;

		if (bigEndian)
		{
			res += value >> 56 & 0xFF;
			res += value >> 48 & 0xFF;
			res += value >> 40 & 0xFF;
			res += value >> 32 & 0xFF;
			res += value >> 24 & 0xFF;
			res += value >> 16 & 0xFF;
			res += value >> 8 & 0xFF;
			res += value & 0xFF;
		}
		else
		{
			res += value & 0xFF;
			res += value >> 8 & 0xFF;
			res += value >> 16 & 0xFF;
			res += value >> 24 & 0xFF;
			res += value >> 32 & 0xFF;
			res += value >> 40 & 0xFF;
			res += value >> 48 & 0xFF;
			res += value >> 56 & 0xFF;
		}

		return res;
	}

	Bytes Bytes::FromUint64(std::uint64_t value, bool bigEndian)
	{
		return FromInt64((std::int64_t)value, bigEndian);
	}

	Bytes Bytes::FromInt32(std::int32_t value, bool bigEndian)
	{
		cnet::Bytes res;

		if(bigEndian)
		{
			res += value >> 24 & 0xFF;
			res += value >> 16 & 0xFF;
			res += value >> 8 & 0xFF;
			res += value & 0xFF;
		}
		else
		{
			res += value & 0xFF;
			res += value >> 8 & 0xFF;
			res += value >> 16 & 0xFF;
			res += value >> 24 & 0xFF;
		}

		return res;
	}

	Bytes Bytes::FromUint32(std::uint32_t value, bool bigEndian)
	{
		return FromInt32((std::int32_t)value, bigEndian);
	}

	Bytes Bytes::FromByte(cnet::byte value)
	{
		cnet::Bytes res;
		res += value;
		return res;
	}

	Bytes Bytes::FromString(std::string value)
	{
		cnet::Bytes res;
		for (size_t i = 0; i < value.size(); i++)
			res += value[i];
		return res;
	}

	Bytes Bytes::FromVector(std::vector<cnet::byte> value)
	{
		cnet::Bytes res;
		res.data = value;
		return res;
	}

	bool Bytes::ToInt64(std::int64_t* out, size_t startIndex, bool bigEndian)
	{
		if (!out)
			return false;

		if (data.size() == 0)
			return false;

		if (startIndex >= data.size())
			return false;

		if (data.size() - startIndex < 8)
			return false;

		cnet::byte* pbyte = (cnet::byte*)&data[startIndex];
		if (bigEndian)
		{
			int i1 = (*pbyte << 24) | (*(pbyte + 1) << 16) | (*(pbyte + 2) << 8) | (*(pbyte + 3));
			int i2 = (*(pbyte + 4) << 24) | (*(pbyte + 5) << 16) | (*(pbyte + 6) << 8) | (*(pbyte + 7));
			*out = (std::uint32_t)i2 | ((std::int64_t)i1 << 32);
			return true;
		}
		else
		{
			int i1 = (*pbyte) | (*(pbyte + 1) << 8) | (*(pbyte + 2) << 16) | (*(pbyte + 3) << 24);
			int i2 = (*(pbyte + 4)) | (*(pbyte + 5) << 8) | (*(pbyte + 6) << 16) | (*(pbyte + 7) << 24);
			*out = (std::uint32_t)i1 | ((std::int64_t)i2 << 32);
			return true;
		}
	}

	bool Bytes::ToUint64(std::uint64_t* out, size_t startIndex, bool bigEndian)
	{
		return ToInt64((std::int64_t*)out,startIndex, bigEndian);
	}
	bool Bytes::ToInt32(std::int32_t* out, size_t startIndex, bool bigEndian)
	{
		if (!out)
			return false;

		if (data.size() == 0)
			return false;

		if (startIndex >= data.size())
			return false;

		if (data.size() - startIndex < 4)
			return false;

		cnet::byte* pbyte = (cnet::byte*)&data[startIndex];
		if (bigEndian) {
			*out = (*pbyte << 24) | (*(pbyte + 1) << 16) | (*(pbyte + 2) << 8) | (*(pbyte + 3));
			return true;
		}
		else {
			*out = (*pbyte) | (*(pbyte + 1) << 8) | (*(pbyte + 2) << 16) | (*(pbyte + 3) << 24);
			return true;
		}
	}

	bool Bytes::ToUint32(std::uint32_t* out, size_t startIndex, bool bigEndian)
	{
		return ToInt32((std::int32_t*)out,startIndex, bigEndian);
	}

	std::string Bytes::AsString()
	{
		std::string res = "[";
		for (size_t i = 0; i < data.size(); i++)
		{
			cnet::byte hi = (data[i] >> 4) & 0xf;
			cnet::byte lo = data[i] & 0xf;

			res += "0x";
			res += hi < 10 ? hi + '0' : 'A' + (hi - 10);
			res += lo < 10 ? lo + '0' : 'A' + (lo - 10);
			res += ",";
			
		}
		res = res.substr(0, res.size() - 1) + ']';
		return res;
	}

	std::string Bytes::ToString()
	{
		const char* str = (char*)data.data();
		if (!str)
			return "";
		std::string res = str;
		res.resize(data.size());
		if (str[data.size() - 1] != '\0')
			res += '\0';
		return res;
	}

	cnet::Bytes Bytes::Slice(size_t fromIndex, size_t toIndex)
	{
		if (toIndex == -1)
			toIndex = data.size();
		if (toIndex < fromIndex)
			throw std::runtime_error("to index should be bigger then from");
		if(fromIndex < 0)
			throw std::runtime_error("from index should be bigger then -1");
		if (fromIndex > data.size())
			throw std::runtime_error("from index should be smaller then size");
		if (toIndex > data.size())
			throw std::runtime_error("to index should be smaller then size");

		std::vector<cnet::byte> tmp(data.begin() + fromIndex, data.begin() + toIndex);
		return cnet::Bytes(tmp);
	}

	Bytes& Bytes::operator+=(const Bytes& rhs)
	{
		for (size_t i = 0; i < rhs.data.size(); i++)
			data.push_back(rhs.data[i]);
		return *this;
	}

	Bytes& Bytes::operator+=(const std::vector<cnet::byte>& rhs)
	{
		for (size_t i = 0; i < rhs.size(); i++)
			data.push_back(rhs[i]);
		return *this;
	}

	Bytes& Bytes::operator+=(const cnet::byte& rhs)
	{
		data.push_back(rhs);
		return *this;
	}

	Bytes Bytes::operator+(const Bytes& other)
	{
		Bytes res;
		res += *this;
		res += other;
		return res;
	}
}