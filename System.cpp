#include "System.h"
#include "Student.h"
#include "Problem.h"

bool System::isSystemActive = false;

System::System()
	:isThisActive(false),
	studentList(new BBHList<Student>),
	problemList(new BBHList<Problem>),
	stuList(*studentList),
	probList(*problemList)
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

bool System::AddStudent(const std::string _stuID, const std::string _name, const bool _sex, const unsigned int _age, const std::string probID)
{
	if (!isThisActive)
	{
		return false;
	}
	if (probID == "")
	{
		return studentList->AddElement(Student(_stuID, _name, _sex, _age, nullptr));
	}
	for (unsigned int i = 0; i < probList.GetSize(); i++)
	{
		if (probID == probList[i].GetID() && !probList[i].IsFull())
		{
			return studentList->AddElement(Student(_stuID, _name, _sex, _age, &probList[i]));
		}
	}
	return false;
}

bool System::ChangeProblemInfo(const Problem* prob, const std::string str, ProbStringInfo targetInfo)
{
	if ((!isThisActive) || !(prob))
	{
		return false;
	}
	switch (targetInfo)
	{
	case ProbStringInfo::ID:
		prob->id = str;
		return true;
	case ProbStringInfo::Title:
		prob->title = str;
		return true;
	case ProbStringInfo::TeacherName:
		prob->teacherName = str;
		return true;
	case ProbStringInfo::Requirement:
		prob->requirement = str;
		return true;
	default:
		return false;
	}
}

bool System::ChangeProblemInfo(const Problem* prob, const unsigned int max)
{
	if ((!isThisActive) || !(prob))
	{
		return false;
	}
	if (max < prob->nowNum)
	{
		return false;
	}
	prob->maxNum = max;
	return true;
}

bool System::DeleteProblem(unsigned int index)
{
	if (!isThisActive || (!FunctionLibrary::IsInRange(index, 0u, probList.GetSize() - 1, true)))
	{
		return false;
	}
	if (probList[index].GetNowNumber())
	{
		return false;
	}
	return probList.DeleteElement(index);
}

bool System::ChangeStudentInfo(const Student* targetStu, const std::string str, StuStringInfo targetInfo)
{
	if (!isThisActive || !(targetStu))
	{
		return false;
	}
	switch (targetInfo)
	{
	case StuStringInfo::StuID:
		targetStu->stuID = str;
		return true;
	case StuStringInfo::Name:
		targetStu->name = str;
		return true;
	default:
		return false;
	}
}

bool System::ChangeStudentInfo(const Student* targetStu, const bool sex)
{
	if (!isThisActive || !(targetStu))
	{
		return false;
	}
	targetStu->sex = sex;
	return true;
}

bool System::ChangeStudentInfo(const Student* targetStu, const unsigned int age)
{
	if (!isThisActive || !(targetStu))
	{
		return false;
	}
	if (age <= 0)
	{
		return false;
	}
	targetStu->age = age;
	return true;
}

bool System::ChangeStudentInfo(const Student* targetStu, const Problem* prob)
{
	if ((!isThisActive) || !(targetStu) || (!prob))
	{
		return false;
	}
	return targetStu->setProblem(prob);
}

bool System::DeleteStudent(const unsigned int index)
{
	if (!isThisActive || !FunctionLibrary::IsInRange(index, 0u, stuList.GetSize() - 1, true))
	{
		return false;
	}
	return stuList.DeleteElement(index);
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
		result += probList[i].Output(OutputMethod::Short) + "\n";
	}
	return result;
}