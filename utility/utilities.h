#pragma once
#include <string>
#include <cstdint>
#include <functional>
#include <vector>

namespace utils
{
	std::string GetUsername();
	std::uint8_t* PatternScan(const char* moduleName, const char* pattern);

	template <typename Return, typename ... Arguments>
	constexpr Return CallVFunc(void* vmt, const std::uint32_t index, Arguments ... args) noexcept
	{
		using Function = Return(__thiscall*)(void*, decltype(args)...);
		return (*static_cast<Function**>(vmt))[index](vmt, args...);
	}

	__forceinline std::vector<char> HexToBytes(const std::string& hex) 
	{
		std::vector<char> res;

		for (auto i = 0u; i < hex.length(); i += 2) 
		{
			std::string byteString = hex.substr(i, 2);
			char byte = (char)strtol(byteString.c_str(), NULL, 16);
			res.push_back(byte);
		}

		return res;
	}

	__forceinline std::string BytesToString(unsigned char* data, int len) 
	{
		constexpr char hexmap[] = { '0', '1', '2', '3', '4', '5', '6', '7',
									'8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
		std::string res(len * 2, ' ');

		for (int i = 0; i < len; ++i) 
		{
			res[2 * i] = hexmap[(data[i] & 0xF0) >> 4];
			res[2 * i + 1] = hexmap[data[i] & 0x0F];
		}
		return res;
	}

	__forceinline std::vector<std::string> Split(const std::string& str, const char* delim) 
	{
		std::vector<std::string> res;
		char* pTempStr = _strdup(str.c_str());
		char* context = NULL;
		char* pWord = strtok_s(pTempStr, delim, &context);

		while (pWord != NULL) 
		{
			res.push_back(pWord);
			pWord = strtok_s(NULL, delim, &context);
		}

		free(pTempStr);

		return res;
	}
}