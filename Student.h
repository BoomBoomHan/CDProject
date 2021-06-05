#pragma once
#include <string>

class Student
{
private:
	Student(const Student&);//���ɿ���
	const Student operator =(const Student&) { return *this; }//���ɸ�ֵ
	std::string stuID;
	std::string name;
	bool sex;//1Ϊ�У�0ΪŮ
	unsigned int age;
	class Problem* selectedProblem;
public:
	Student(const std::string, const std::string, const bool, const unsigned int, const Problem*);
	~Student();
	std::string GetID();
	std::string Output();
};

