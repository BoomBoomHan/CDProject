#pragma once
#include "BBHList.h"
#include "Enums.h"


class System//课程设计选题系统
{
private:
	bool isThisActive;
	static bool isSystemActive;
private:
	BBHList<class Student>* studentList;
	BBHList<class Problem>* problemList;
private:
	BBHList<Student>& stuList;
	BBHList<Problem>& probList;

public:
	//缺省构造
	System();
	//析构
	~System();
	//通过--编号 标题 指导老师 要求 最大人数--添加课设题目,当且仅当系统激活时可用,成功时返回真
	bool AddProblem(const std::string, const std::string, const std::string, const std::string, const unsigned int);
	//通过--学号 姓名 性别(1男0女) 年龄 选择的题目--添加学生,当且仅当系统激活时可用,成功时返回真
	bool AddStudent(const std::string, const std::string, const bool, const unsigned int, const Problem* = nullptr);
	//修改指定问题的编号、标题、指导老师、要求,若成功则返回真
	bool ChangeProblemInfo(const Problem*, const std::string, ProbStringInfo);

	//修改指定问题的最大选题人数,若成功则返回真
	bool ChangeProblemInfo(const Problem*, const unsigned int);
	//修改指定学生的学号、姓名,若成功则返回真
	bool ChangeStudentInfo(const Student*, const std::string, StuStringInfo);
	//修改指定学生的性别,若成功则返回真
	bool ChangeStudentInfo(const Student*, const bool);
	//修改指定学生的年龄,若成功则返回真
	bool ChangeStudentInfo(const Student*, const unsigned int);
	//修改指定学生的选题,若成功则返回真
	bool ChangeStudentInfo(const Student*, const Problem*);

	std::string OutputStu();
	std::string OutputProb();
};

