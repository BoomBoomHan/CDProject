#include "System.h"
#include "Student.h"
#include "Problem.h"
#include <iostream>

bool System::isSystemActive = false;

void System::selfDelete_stu(const Student& targetStu)
{
	targetStu.isDeleted = true;
}

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
			const Problem* target = &probList[i];
			return studentList->AddElement(Student(_stuID, _name, _sex, _age, target));
			/*const bool result = studentList->AddElement(Student(_stuID, _name, _sex, _age, nullptr));
			ChangeStudentInfo(&stuList[stuList.GetSize() - 1], &probList[i]);
			return result;*/
		}
	}
	return false;
}

bool System::AddStudent(const std::string _stuID, const std::string _name, const bool _sex, const unsigned int _age, const unsigned int index)
{
	if (!isThisActive || (!FunctionLibrary::IsInRange(index, 0u, probList.GetSize(), true)))
	{
		return false;
	}
	return studentList->AddElement(Student(_stuID, _name, _sex, _age, &probList[index]));
}

bool System::ChangeProblemInfo(const Problem* targetProb, const std::string str, ProbStringInfo targetInfo)
{
	if ((!isThisActive) || (!targetProb))
	{
		return false;
	}
	switch (targetInfo)
	{
	case ProbStringInfo::ID:
		targetProb->id = str;
		return true;
	case ProbStringInfo::Title:
		targetProb->title = str;
		return true;
	case ProbStringInfo::TeacherName:
		targetProb->teacherName = str;
		return true;
	case ProbStringInfo::Requirement:
		targetProb->requirement = str;
		return true;
	default:
		return false;
	}
}

bool System::ChangeProblemInfo(const Problem* targetProb, const unsigned int max)
{
	if ((!isThisActive) || (!targetProb))
	{
		return false;
	}
	if (max < targetProb->nowNum)
	{
		return false;
	}
	targetProb->maxNum = max;
	return true;
}

bool System::DeleteProblem(const Problem* targetProb)
{
	if ((!isThisActive) || (!targetProb))
	{
		return false;
	}
	if (targetProb->GetNowNumber())
	{
		return false;
	}
	unsigned int index = -1;
	for (unsigned int i = 0; i < probList.GetSize(); i++)
	{
		if (targetProb == &probList[i])
		{
			index = i;
			break;
		}
	}
	const bool deleteResult = probList.DeleteElement(index);
	if (!deleteResult)
	{
		return false;
	}
	for (; index < probList.GetSize(); index++)
	{
		Problem* prob = &probList[index];
		for (unsigned int i = 0; i < stuList.GetSize(); i++)
		{
			Student* stu = &stuList[i];
			if (prob->GetID() == stu->GetProblem()->GetID())
			{
				std::cout << "!!!" << std::endl;
				stu->setProblem(&probList[index - 1]);
			}
		}
	}
	return true;
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

bool System::DeleteStudent(const Student* targetStu)
{
	/*if (!isThisActive || !FunctionLibrary::IsInRange(index, 0u, stuList.GetSize() - 1, true))
	{
		return false;
	}
	selfDelete_stu(stuList[index]);
	return stuList.DeleteElement(index);*/
	return false;
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

std::string System::OutputProb(OutputMethod method)
{
	std::string result;
	const std::string anotherEnter = (method == OutputMethod::Complete) ? "\n" : "";
	for (unsigned int i = 0; i < problemList->GetSize(); i++)
	{
		result += probList[i].Output(method) + "\n" + anotherEnter;
	}
	return result;
}

void System::Test()
{
	using namespace std;
	AddProblem("010", "课程设计选题系统", "艾勇", "暂无", 30);
	AddProblem("002", "通讯录", "杨喜敏", "无", 66);
	AddProblem("003", "火车站购票系统", "姜卓睿", "无", 90);
	AddProblem("666", "新思路签到系统", "朱凯闻", "无", 5);
	AddStudent("20210122", "张三", 1, 19, "666");
	//sys->AddStudent("20210122", "张三", 1, 19, "666");
	/*cout << OutputProb(OutputMethod::Complete);
	cout << "------------------------" << endl << endl;
	cout << OutputStu();*/
	DeleteProblem(&probList[0]);
	//cout << "------------------------" << endl << endl;
	cout << OutputProb(OutputMethod::Complete);
	cout << "------------------------" << endl << endl;
	cout << OutputStu();
}