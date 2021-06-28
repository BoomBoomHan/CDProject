#include "System.h"
#include "Student.h"
#include "Problem.h"
#include <iostream>
#include <fstream>

bool System::isSystemActive = false;

System::System(const std::string userName, const std::string password)
	:isThisActive(false),
	studentList(new BBHList<Student>),
	problemList(new BBHList<Problem>),
	stuList(*studentList),
	probList(*problemList),
	databasePath("Library"),
	stuListFileName("Students.dat"),
	probListFileName("Problems.dat"),
	correspondingAccount{ "BoomBoomHan","123456" }
{
	if ((!isSystemActive) && (userName == correspondingAccount[0]) && (password == correspondingAccount[1]))
	{
		isSystemActive = true;
		isThisActive = true;
	}
	if (isThisActive)
	{
		std::ifstream inputFile;
		//读取题目
		BBHList<unsigned int> nowNums;
		std::string _id;//编号
		std::string _title;//标题
		std::string _teacherName;//指导老师
		std::string _requirement;//要求
		unsigned int _maxNum = 0;//最大选课人数
		unsigned int _nowNum = 0;//已选人数
		if (FunctionLibrary::OpenFile(inputFile, databasePath + "/" + probListFileName))
		{
			while (!inputFile.eof())
			{
				std::getline(inputFile, _id);
				if (_id == "")
				{
					break;
				}
				std::getline(inputFile, _title);
				std::getline(inputFile, _teacherName);
				std::getline(inputFile, _requirement);
				inputFile >> _maxNum >> _nowNum;
				inputFile.get();
				AddProblem(_id, _title, _teacherName, _requirement, _maxNum, 0u);
				nowNums.AddElement(_nowNum, false);
			}
		}
		//读取学生
		std::string _stuID;//学号
		std::string _name;//姓名
		bool _sex;//1为男，0为女
		unsigned int _age;//年龄
		std::string _selectedProblemTitle;//选择的题目编号
		if (FunctionLibrary::OpenFile(inputFile, databasePath + "/" + stuListFileName))
		{
			while (!inputFile.eof())
			{
				std::getline(inputFile, _stuID);
				if (_stuID == "")
				{
					break;
				}
				std::getline(inputFile, _name);
				inputFile >> _sex >> _age;
				inputFile.get();
				std::getline(inputFile, _selectedProblemTitle);
				AddStudent(_stuID, _name, _sex, _age, _selectedProblemTitle);
			}
		}
		FunctionLibrary::CloseFile(inputFile);
		//数据检查
		for (unsigned int i = 0; i < probList.GetSize(); i++)
		{
			//std::cout << probList[i].GetNowNumber() << "," << nowNums[i] << std::endl;
			if (probList[i].GetNowNumber() != nowNums[i])
			{
				ERROR_SELF_REPAIR();
				break;
			}
		}
	}
}

System::~System()
{
	Save();
	//关闭系统
	isSystemActive = false;
	delete studentList;
	delete problemList;
}

void System::Save()
{
	std::ofstream outputFile;
	std::string result;
	//保存题目
	if (FunctionLibrary::OpenFile(outputFile, FunctionLibrary::CreateFolder(databasePath) + "/" + probListFileName) && probList.GetSize())
	{
		for (unsigned int i = 0; i < probList.GetSize(); i++)
		{
			result += probList[i].Output(OutputMethod::Save);
		}
		result.erase(result.end() - 1);
		outputFile << result;
		result.clear();
	}
	//保存学生
	if (FunctionLibrary::OpenFile(outputFile, FunctionLibrary::CreateFolder(databasePath) + "/" + stuListFileName) && stuList.GetSize())
	{
		for (unsigned int i = 0; i < stuList.GetSize(); i++)
		{
			result += stuList[i].Output(OutputMethod::Save);
		}
		result.erase(result.end() - 1);
		outputFile << result;
		result.clear();
	}
	FunctionLibrary::CloseFile(outputFile);
}

void System::ERROR_SELF_REPAIR()
{
	std::cout << "ERROR!!!" << std::endl;
	for (unsigned int i = 0; i < stuList.GetSize(); i++)
	{
		stuList[i].selectedProblem = nullptr;
	}
	for (unsigned int i = 0; i < probList.GetSize(); i++)
	{
		probList[i].nowNum = 0;
	}
}

void System::CLEAR_DATAS()
{
	remove((databasePath + "/" + stuListFileName).c_str());
	remove((databasePath + "/" + probListFileName).c_str());
}

bool System::AddProblem(const std::string _id, const std::string _title, const std::string _teacherName, const std::string _requirement, const unsigned int _maxNum, const unsigned int _nowNum)
{
	if (!isThisActive)
	{
		return false;
	}
	Problem prob(_id, _title, _teacherName, _requirement, _maxNum);
	prob.nowNum = _nowNum;
	return problemList->AddElement(prob);
}

bool System::AddStudent(const std::string _stuID, const std::string _name, const bool _sex, const unsigned int _age, const std::string probID)
{
	if ((!isThisActive) || (!stuList.CheckUnique(Student(_stuID, _name, _sex, _age, nullptr))))
	{
		return false;
	}
	if (probID == "" || probID == Student::nullProblemFlag)
	{
		return studentList->AddElement(Student(_stuID, _name, _sex, _age, nullptr));
	}
	Problem* target = nullptr;
	for (unsigned int i = 0; i < probList.GetSize(); i++)
	{
		if (probID == probList[i].GetID())
		{
			target = (!probList[i].IsFull()) ? &probList[i] : nullptr;
			break;
		}
	}
	return studentList->AddElement(Student(_stuID, _name, _sex, _age, target));
}

bool System::AddStudent(const std::string _stuID, const std::string _name, const bool _sex, const unsigned int _age, const unsigned int index)
{
	if ((!isThisActive) || (!FunctionLibrary::IsInRange(index, 0u, probList.GetSize(), true)) || (!stuList.CheckUnique(Student(_stuID, _name, _sex, _age, nullptr))))
	{
		return false;
	}
	const Problem* target = (!probList[index].IsFull()) ? &probList[index] : nullptr;
	return studentList->AddElement(Student(_stuID, _name, _sex, _age, target));
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

Problem* System::FindProblem(const std::string _id)
{
	if (!isThisActive)
	{
		return nullptr;
	}
	for (unsigned int i = 0; i < probList.GetSize(); i++)
	{
		if (probList[i].GetID() == _id)
		{
			return &probList[i];
		}
	}
	return FindProblem(FunctionLibrary::ToInt(_id) - 1);
}

Problem* System::FindProblem(const unsigned int index)
{
	if ((!isThisActive) || (!FunctionLibrary::IsInRange(index, 0u, probList.GetSize(), true, false)))
	{
		return nullptr;
	}
	return &probList[index];
}

bool System::DeleteProblem(const Problem* targetProb)
{
	if ((!isThisActive) || (!targetProb) || (!probList.GetSize()))
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
	if (index == -1)
	{
		return false;
	}
	const unsigned int deleteTarget = index;
	for (index += 1; index < probList.GetSize(); index++)
	{
		Problem* prob = &probList[index];
		for (unsigned int i = 0; i < stuList.GetSize(); i++)
		{
			Student* stu = &stuList[i];
			if (prob == stu->GetProblem())
			{
				stu->selectedProblem = &probList[index - 1];
			}
		}
	}
	return probList.DeleteElement(deleteTarget);
}

bool System::DeleteProblem(const unsigned int index)
{
	return DeleteProblem(&probList[index]);
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

Student* System::FindStudent(const std::string _stuID)
{
	if (!isThisActive)
	{
		return nullptr;
	}
	for (unsigned int i = 0; i < stuList.GetSize(); i++)
	{
		if (stuList[i].GetID() == _stuID)
		{
			return &stuList[i];
		}
	}
	return FindStudent(FunctionLibrary::ToInt(_stuID) - 1);
}

Student* System::FindStudent(const unsigned int index)
{
	if ((!isThisActive) || (!FunctionLibrary::IsInRange(index, 0u, stuList.GetSize(), true, false)))
	{
		return nullptr;
	}
	return &stuList[index];
}

bool System::DeleteStudent(const Student* targetStu)
{
	if ((!isThisActive) || (!targetStu) || (!stuList.GetSize()))
	{
		return false;
	}
	unsigned int index = -1;
	for (unsigned int i = 0; i < stuList.GetSize(); i++)
	{
		if (targetStu == &stuList[i])
		{
			index = i;
			break;
		}
	}
	if (index == -1)
	{
		return false;
	}
	targetStu->selfDelete();
	return stuList.DeleteElement(index);
}

bool System::DeleteStudent(const unsigned int index)
{
	return DeleteStudent(&stuList[index]);
}

std::string System::SearchProblem(const std::string str)
{
	BBHList<std::string> teacherList;
	std::string result;
	for (unsigned int i = 0; i < probList.GetSize(); i++)
	{
		const Problem& prob = probList[i];
		const std::string id = prob.GetID();
		const std::string title = prob.GetTitle();
		const std::string teacherName = prob.GetTeacher();
		if (id == str)
		{
			result += "编号为" + str + "的选题为:" + prob.Output(OutputMethod::IgnoreID);
			break;
		}
		else if (title == str)
		{
			result += "标题为\"" + str + "\"的选题为:" + prob.Output(OutputMethod::Short);
			break;
		}
		else if (teacherName == str)
		{
			teacherList.AddElement(prob.Output(OutputMethod::Short));
		}
	}
	if (teacherList.GetSize())
	{
		result += "指导老师为" + str + "的选题有:\n";
		for (unsigned int i = 0; i < teacherList.GetSize(); i++)
		{
			result += teacherList[i] + "\n";
		}
	}
	if (result.empty())
	{
		result = "未找到与\"" + str + "\"有关的选题。\n";
	}
	return result;
}

std::string System::SearchStudent(const std::string str, const int method)
{
	std::string result;
	BBHList<std::string> idList;
	for (unsigned int i = 0; i < stuList.GetSize(); i++)
	{
		const Student& stu = stuList[i];
		if (method == 1)
		{
			const std::string stuID = stu.GetID();
			const std::string name = stu.GetName();
			if (stuID == str)
			{
				result += "学号为" + str + "的学生为:" + stu.Output(OutputMethod::IgnoreID);
				break;
			}
			else if (name == str)
			{
				result += "姓名为\"" + str + "\"的学生为:" + stu.Output(OutputMethod::Short);
				break;
			}
		}
		else if (method == 2)
		{
			const Problem* prob = stu.GetProblem();
			const std::string id = (prob ? prob->GetID() : "");
			if (id == str)
			{
				idList.AddElement(stu.Output(OutputMethod::Short) + "\n");
			}
		}
	}
	if (idList.GetSize())
	{
		result += "选题编号为" + str + "的学生有:\n";
		for (unsigned int i = 0; i < idList.GetSize(); i++)
		{
			result += idList[i];
		}
	}
	if (result.empty())
	{
		result = "未找到与\"" + str + "\"有关的学生。\n";
	}
	return result;
}

std::string System::OutputStu(OutputMethod method)
{
	if (stuList.GetSize() == 0)
	{
		return "空!";
	}
	std::string result;
	const std::string anotherEnter = (method == OutputMethod::Complete) ? "\n" : "";
	for (unsigned int i = 0; i < studentList->GetSize(); i++)
	{
		result += (method == OutputMethod::Short || method == OutputMethod::IgnoreID) ? (FunctionLibrary::ToString(i + 1) + ":") : "";
		result += stuList[i].Output(method) + "\n" + anotherEnter;
	}
	return result;
}

std::string System::OutputProb(OutputMethod method)
{
	if (probList.GetSize() == 0)
	{
		return "空!";
	}
	std::string result;
	const std::string anotherEnter = (method == OutputMethod::Complete) ? "\n" : "";
	for (unsigned int i = 0; i < problemList->GetSize(); i++)
	{
		result += (method == OutputMethod::Short || method == OutputMethod::IgnoreID) ? (FunctionLibrary::ToString(i + 1) + ":") : "";
		result += probList[i].Output(method) + "\n" + anotherEnter;
	}
	return result;
}

bool System::IsThisActive()
{
	return isThisActive;
}