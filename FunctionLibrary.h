#pragma once
#include <string>
#include <sstream>

class FunctionLibrary//公共函数库
{
public:
	template<typename T>
	static std::string ToString(const T number)//将整数,小数等转换为字符串
	{
		std::stringstream stream;
		std::string result;
		stream << number;
		stream >> result;
		stream.clear();
		return result;
	}

	template<typename T>
	static bool IsInRange(const T target, const T min, const T max, bool closedInterval = false)//判断目标数是否在min和max间,第四个参数为是否是闭区间
	{
		if (closedInterval)
		{
			return (target <= max&& target >= min);
		}
		return (target < max&& target > min);
	}
};

