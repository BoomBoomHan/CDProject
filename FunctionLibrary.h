#pragma once
#include <string>
#include <sstream>

class FunctionLibrary//����������
{
public:
	template<typename T>
	static std::string ToString(const T number)//������,С����ת��Ϊ�ַ���
	{
		std::stringstream stream;
		std::string result;
		stream << number;
		stream >> result;
		stream.clear();
		return result;
	}

	template<typename T>
	static bool IsInRange(const T target, const T min, const T max, bool closedInterval = false)//�ж�Ŀ�����Ƿ���min��max��,���ĸ�����Ϊ�Ƿ��Ǳ�����
	{
		if (closedInterval)
		{
			return (target <= max&& target >= min);
		}
		return (target < max&& target > min);
	}
};

