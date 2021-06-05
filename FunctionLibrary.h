#pragma once
#include <string>
#include <sstream>

class FunctionLibrary//公共函数库
{
public:
	template<typename T>
	static std::string ToString(T number)//将整数,小数等转换为字符串
	{
		std::stringstream stream;
		std::string result;
		stream << number;
		stream >> result;
		stream.clear();
		return result;
	}
};

