#pragma once
#include <string>
#include <sstream>

class FunctionLibrary//����������
{
public:
	template<typename T>
	static std::string ToString(T number)//������,С����ת��Ϊ�ַ���
	{
		std::stringstream stream;
		std::string result;
		stream << number;
		stream >> result;
		stream.clear();
		return result;
	}
};

