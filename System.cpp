#include "System.h"
#include "Student.h"
#include "Problem.h"

bool System::isSystemActive = false;

System::System()
	:isThisActive(false),
	studentList(new BBHList<Student>),
	problemList(new BBHList<Problem>)
{
	if (!isSystemActive)
	{
		isSystemActive = true;
		isThisActive = true;
	}
}

System::~System()
{
	isSystemActive = false;
	delete[] studentList;
	delete[] problemList;
}

bool System::AddProblem(const std::string _id, const std::string _title, const std::string _teacherName, const std::string _requirement, const unsigned int _maxNum)
{
	if (!isThisActive)
	{
		return false;
	}
	return problemList->AddElement(Problem(_id, _title, _teacherName, _requirement, _maxNum));
}

bool System::AddStudent(const std::string _stuID, const std::string _name, const bool _sex, const unsigned int _age, const Problem* _prob)
{
	if (!isThisActive)
	{
		return false;
	}
	return studentList->AddElement(Student(_stuID, _name, _sex, _age, _prob));
}

bool System::ChangeStudentInfo(const Student& targetStu, const std::string str, StuStringInfo targetInfo)
{
	if (!isThisActive)
	{
		return false;
	}
	switch (targetInfo)
	{
	case StuStringInfo::StuID:
		targetStu.stuID = str;
		return true;
	case StuStringInfo::Name:
		targetStu.name = str;
		return true;
	default:
		return false;
	}
}

bool System::ChangeStudentInfo(const Student& targetStu, const bool sex)
{
	if (!isThisActive)
	{
		return false;
	}
	return true;
}

bool System::ChangeStudentInfo(const Student& targetStu, const unsigned int age)
{
	if (!isThisActive)
	{
		return false;
	}
	return true;
}

bool System::ChangeStudentInfo(const Student& targetStu, const Problem* prob)
{
	if ((!isThisActive) || (!prob))
	{
		return false;
	}
	return targetStu.SetProblem(prob);
}

std::string System::OutputStu()
{
	std::string result;
	for (unsigned int i = 0; i < studentList->GetSize(); i++)
	{
		result += (*studentList)[i].Output() + "\n";
	}
	return result;
}

std::string System::OutputProb()
{
	std::string result;
	for (unsigned int i = 0; i < problemList->GetSize(); i++)
	{
		result += (*problemList)[i].Output(OutputMethod::Short) + "\n";
	}
	return result;
}