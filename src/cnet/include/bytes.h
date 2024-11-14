#ifndef _CNET_BYTES_H
#define _CNET_BYTES_H

#include <vector>
#include <string>
#include <cinttypes>

namespace cnet
{
	typedef std::uint8_t byte;
	class Bytes
	{
		friend class Socket;
	public:

		enum SliceOptions
		{
			End = -1
		};

		std::size_t Size() { return data.size(); }

		bool ToInt64(std::int64_t* out, size_t startIndex = 0, bool bigEndian = true);
		bool ToUint64(std::uint64_t* out, size_t startIndex = 0, bool bigEndian = true);
		bool ToInt32(std::int32_t* out, size_t startIndex = 0, bool bigEndian = true);
		bool ToUint32(std::uint32_t* out, size_t startIndex = 0, bool bigEndian = true);

		std::string AsString();
		std::string ToString();

		cnet::Bytes Slice(size_t from, size_t to = SliceOptions::End);

		static Bytes FromInt64(std::int64_t value, bool bigEndian = true);
		static Bytes FromUint64(std::uint64_t value, bool bigEndian = true);
		static Bytes FromInt32(std::int32_t value, bool bigEndian = true);
		static Bytes FromUint32(std::uint32_t value, bool bigEndian = true);
		static Bytes FromString(std::string value);

		Bytes& operator+=(const Bytes& rhs);
		Bytes& operator+=(const std::vector<cnet::byte>& rhs);
		Bytes& operator+=(const cnet::byte& rhs);
		Bytes operator+(const Bytes& other);

	private:
		Bytes() {};
		Bytes(std::vector<cnet::byte>& data) { this->data = std::move(data); }
		std::vector<cnet::byte> data;
	};
}

#endif