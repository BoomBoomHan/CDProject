#pragma once
#include <string>
#include <sstream>

class FunctionLibrary//公共函数库
{
public:
	//将整数,小数等转换为字符串
	template<typename T>
	static std::string ToString(const T number)
	{
		std::stringstream stream;
		std::string result;
		stream << number;
		stream >> result;
		stream.clear();
		return result;
	}

	//判断目标数是否在min和max间,第四,五个参数为是否是闭区间
	template<typename T>
	static bool IsInRange(const T target, const T min, const T max, const bool isLeftClosed = false, const bool isRightClosed = false)
	{
		const bool result1 = isLeftClosed ? (target >= min) : (target > min);
		const bool result2 = isRightClosed ? (target <= max) : (target < max);
		return result1 * result2;
	}
};

