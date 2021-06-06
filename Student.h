#pragma once
#include <string>

class Student
{
private:
	//不可拷贝
	Student(const Student&);
	//不可赋值
	const Student operator =(const Student&) { return *this; }
	std::string stuID;//学号
	std::string name;//姓名
	bool sex;//1为男，0为女
	unsigned int age;//年龄
	mutable class Problem* selectedProblem;//选择的题目
public:
	//学号 姓名 性别(1男0女) 年龄 选择的题目
	Student(const std::string, const std::string, const bool, const unsigned int, const Problem*);
	//析构
	~Student();
	//获取学号(const)
	std::string GetID() const;
	//获取学号
	std::string GetID();
	//获取题目(const)
	Problem* GetProblem() const;
	//获取题目
	Problem* GetProblem();
	//设置题目(const)
	bool SetProblem(const Problem*) const;
	//设置题目
	bool SetProblem(const Problem*);
	//输出为字符串
	std::string Output();
	//若两个学生学号相同则返回真(const)
	bool operator ==(const Student&) const;
	//若两个学生学号相同则返回真
	bool operator ==(const Student&);
};

