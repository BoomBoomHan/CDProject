#pragma once
#include <string>
#include "System.h"

class Student
{
private:
	mutable std::string stuID;//学号
	mutable std::string name;//姓名
	mutable bool sex;//1为男，0为女
	mutable unsigned int age;//年龄
	mutable class Problem* selectedProblem;//选择的题目
private:
	//设置题目(const)
	bool setProblem(const Problem*) const;
	//设置题目
	//bool setProblem(const Problem*);
public:
	//学号 姓名 性别(1男0女) 年龄 选择的题目
	Student(const std::string, const std::string, const bool, const unsigned int, const Problem*);
	//析构
	~Student();
	//获取学号(const)
	std::string GetID() const;
	//获取学号
	//std::string GetID();
	//获取题目(const)
	Problem* GetProblem() const;
	//获取题目
	//Problem* GetProblem();
	//输出为字符串
	std::string Output();
	//若两个学生学号相同则返回真(const)
	bool operator ==(const Student&) const;
	//若两个学生学号相同则返回真
	//bool operator ==(const Student&);
	//此友元函数是System类的成员函数
	friend bool System::ChangeStudentInfo(const Student*, const std::string, StuStringInfo);
	//此友元函数是System类的成员函数
	friend bool System::ChangeStudentInfo(const Student*, const bool);
	//此友元函数是System类的成员函数
	friend bool System::ChangeStudentInfo(const Student*, const unsigned int);
	//此友元函数是System类的成员函数
	friend bool System::ChangeStudentInfo(const Student*, const Problem* b);
};

