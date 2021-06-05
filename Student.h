#pragma once
#include "Problem.h"
#include <string>

class Student
{
private:
	Student(const Student&);//不可拷贝
	const Student operator =(const Student&) { return *this; }//不可赋值
	std::string stuID;
	std::string name;
	bool sex;//1为男，0为女
	unsigned int age;
	Problem* selectedProblem;
public:
	Student(const std::string, const std::string, const bool, const unsigned int, const Problem*);
	~Student();
	std::string GetID();
};

