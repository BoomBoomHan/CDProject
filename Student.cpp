#include "Student.h"
#include "Problem.h"

Student::Student(const std::string _stuID, const std::string _name, const bool _sex, const unsigned int _age, Problem* _prob)
	:stuID(_stuID),
	name(_name),
	sex(_sex),
	age(_age),
	selectedProblem(_prob)
{
	if (_prob)
	{
		setProblem(_prob);
	}
}

Student::~Student()
{
	stuID = '\0';
	name = '\0';
	sex = 0;
	age = 0;
	if (selectedProblem)
	{
		selectedProblem->nowNum--;
	}
}

std::string Student::GetID() const
{
	return stuID;
}

//std::string Student::GetID() 
//{
//	return stuID;
//}

Problem* Student::GetProblem() const
{
	return selectedProblem;
}

//Problem* Student::GetProblem()
//{
//	return const_cast<Problem*>(static_cast<const Student&>(*this).GetProblem());
//}

bool Student::setProblem(const Problem* prob) const
{
	if (!prob)
	{
		return false;
	}
	if (prob->IsFull())
	{
		return false;
	}
	selectedProblem->nowNum--;
	prob->nowNum++;
	selectedProblem = const_cast<Problem*>(prob);
	return true;
}

//bool Student::setProblem(const Problem* prob)
//{
//	if (!prob)
//	{
//		return false;
//	}
//	selectedProblem->nowNum--;
//	prob->nowNum++;
//	selectedProblem = const_cast<Problem*>(prob);
//	return true;
//}

std::string Student::Output()
{
	std::string result;
	result += "学号:" + stuID + "\n姓名:" + name + "\n性别:";
	result += sex ? "男" : "女";
	result += "\n选择题目:";
	if (selectedProblem)
	{
		result += selectedProblem->Output(OutputMethod::Short);
	}
	else
	{
		result += "暂无";
	}
	return result;
}

bool Student::operator ==(const Student& stu) const
{
	return (stuID == stu.GetID()) ? true : false;
}

//bool Student::operator ==(const Student& stu)
//{
//	return (stuID == stu.GetID()) ? true : false;
//}