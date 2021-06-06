#pragma once
#include "BBHList.h"
#include "Student.h"
#include "Problem.h"

class System//课程设计选题系统
{
private:
	bool isThisActive;
	static bool isSystemActive;
private:
	BBHList<Student>* studentList;
	BBHList<Problem>* problemList;

public:
	//缺省构造
	System();
	//析构
	~System();
	//通过--编号 标题 指导老师 要求 最大人数--添加课设题目,当且仅当系统激活时可用,成功时返回真
	bool AddProblem(const std::string, const std::string, const std::string, const std::string, const unsigned int);
	//通过--学号 姓名 性别(1男0女) 年龄 选择的题目--添加学生,当且仅当系统激活时可用,成功时返回真
	bool AddStudent(const std::string, const std::string, const bool, const unsigned int, const Problem*);
};

