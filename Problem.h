#pragma once
#include <string>
#include "Student.h"
#include "Enums.h"

class Problem
{
private:
	//不可赋值
	const Problem operator =(const Problem&) { return *this; }
	mutable std::string id;//编号
	mutable std::string title;//标题
	mutable std::string teacherName;//指导老师
	mutable std::string requirement;//要求
	mutable unsigned int maxNum;//最大选课人数
	mutable unsigned int nowNum;//已选人数
public:
	//编号 标题 指导老师 要求 最大人数
	Problem(const std::string, const std::string, const std::string, const std::string, const unsigned int);
	//析构
	~Problem();
	//获取编号(const)
	std::string GetID() const;
	//获取编号
	std::string GetID();
	//获取标题
	std::string GetTitle();
	//获取最大选题人数
	unsigned int GetMaxNumber();
	//获取已选人数
	unsigned int GetNowNumber();
	//三种不同的输出方式,IgnoreID为只输出标题,Short为输出ID和标题,Complete为全部输出
	std::string Output(OutputMethod);
	//若两者编号相同则返回真(const)
	bool operator ==(const Problem&) const;
	//若两者编号相同则返回真
	bool operator ==(const Problem&);
	//此友元函数是Student类的成员函数const版本
	friend bool Student::SetProblem(const Problem*) const;
	//此友元函数是Student类的成员函数
	friend bool Student::SetProblem(const Problem*);
};

