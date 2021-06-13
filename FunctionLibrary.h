#pragma once
#include <string>
#include <sstream>

class FunctionLibrary//����������
{
public:
	//������,С����ת��Ϊ�ַ���
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

	//�ж�Ŀ�����Ƿ���min��max��,����,�������Ϊ�Ƿ��Ǳ�����
	template<typename T>
	static bool IsInRange(const T target, const T min, const T max, const bool isLeftClosed = false, const bool isRightClosed = false)
	{
		const bool result1 = isLeftClosed ? (target >= min) : (target > min);
		const bool result2 = isRightClosed ? (target <= max) : (target < max);
		return result1 * result2;
	}
};

