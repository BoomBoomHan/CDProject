#pragma once
#include "BBHList.h"
#include "Enums.h"

class System//课程设计选题系统类
{
private:
	bool isThisActive;
	static bool isSystemActive;
private:
	BBHList<class Student>* studentList;
	BBHList<class Problem>* problemList;
	BBHList<Student>& stuList;
	BBHList<Problem>& probList;
public:
	//缺省构造
	System();
	//析构函数,保存并释放所有元素
	~System();

	//通过--编号 标题 指导老师 要求 最大人数--添加课设题目,当且仅当系统激活时可用,成功时返回真
	bool AddProblem(const std::string, const std::string, const std::string, const std::string, const unsigned int);
	//通过--学号 姓名 性别(1男0女) 年龄 选择的题目编号--添加学生,当且仅当系统激活时可用,成功时返回真
	bool AddStudent(const std::string, const std::string, const bool, const unsigned int, const std::string = "");
	//通过--学号 姓名 性别(1男0女) 年龄 题目列表的序号--添加学生,当且仅当系统激活时可用,成功时返回真
	bool AddStudent(const std::string, const std::string, const bool, const unsigned int, const unsigned int);
	
	//修改指定问题的编号、标题、指导老师、要求,当且仅当系统激活时可用,若成功则返回真
	bool ChangeProblemInfo(const Problem*, const std::string, ProbStringInfo);
	//修改指定问题的最大选题人数,当且仅当系统激活时可用,若成功则返回真
	bool ChangeProblemInfo(const Problem*, const unsigned int);
	//删除选题,如果该题已经有学生选择则不能删除,当且仅当系统激活时可用,若成功则返回真
	bool DeleteProblem(const Problem*);//未完成

	//修改指定学生的学号、姓名,当且仅当系统激活时可用,若成功则返回真
	bool ChangeStudentInfo(const Student*, const std::string, StuStringInfo);
	//修改指定学生的性别,当且仅当系统激活时可用,若成功则返回真
	bool ChangeStudentInfo(const Student*, const bool);
	//修改指定学生的年龄,当且仅当系统激活时可用,若成功则返回真
	bool ChangeStudentInfo(const Student*, const unsigned int);
	//修改指定学生的选题,当且仅当系统激活时可用,若成功则返回真
	bool ChangeStudentInfo(const Student*, const Problem*);
	//删除学生,当且仅当系统激活时可用,若成功则返回真
	bool DeleteStudent(const Student*);//未完成

	std::string OutputStu();
	std::string OutputProb(OutputMethod);
	void Test();
};

