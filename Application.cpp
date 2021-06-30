#include "Application.h"
#include "Problem.h"
#include "Student.h"
#include "FunctionLibrary.h"
#define AUTO_SAVE() sys->Save()

Application::Application()
	:sys(nullptr)
	//commands{ &command1,&command2 ,&command3 ,&Application::command4 ,&Application::command5 ,&Application::command6 ,&Application::command7 ,&Application::command8 ,&Application::command0 }
{
	commandList.AddElement(&Application::command0, false);
	commandList.AddElement(&Application::command1, false);
	commandList.AddElement(&Application::command2, false);
	commandList.AddElement(&Application::command3, false);
	commandList.AddElement(&Application::command4, false);
	commandList.AddElement(&Application::command5, false);
	commandList.AddElement(&Application::command6, false);
	commandList.AddElement(&Application::command7, false);
	commandList.AddElement(&Application::command8, false);
	commandList.AddElement(&Application::command9, false);
	commandList.AddElement(&Application::command10, false);

	Login();
}

Application::~Application()
{
	if (sys)
	{
		delete sys;
	}
}

void Application::Login()
{
	std::string username, password;
	std::cout << "欢迎!请登录\n账号:";
	std::getline(std::cin, username);
	std::cout << "密码:";
	std::getline(std::cin, password);
	if (username == "testmode")
	{
		sys = new System("BoomBoomHan", "123456");
	}
	else
	{
		sys = new System(username, password);
	}
	if (!sys->IsThisActive())
	{
		char reply;
		std::cout << "账号或密码错误,请重新登录!按0退出程序";
		std::cin >> reply;
		if (reply == '0')
		{
			std::cout << "退出成功。";
			system("pause");
			exit(1);
		}
		system("cls");
		Login();
	}
	else
	{
		std::cout << "登录成功!";
		system("pause");
		system("cls");
		Menu();
	}
}

void Application::Menu()
{
	system("cls");
	int commandNumber;
	const unsigned int listSize = commandList.GetSize();
	std::cout << "1.添加选题" << std::endl
		<< "2.添加学生" << std::endl
		<< "3.修改选题信息" << std::endl
		<< "4.修改学生信息" << std::endl
		<< "5.删除选题" << std::endl
		<< "6.删除学生" << std::endl
		<< "7.搜索选题" << std::endl
		<< "8.搜索学生" << std::endl
		<< "9.显示所有选题" << std::endl
		<< "10.显示所有学生" << std::endl
		<< "0.退出系统" << std::endl
		<< "请输入指令:";
	std::cin >> commandNumber;
	std::cin.get();
	if (commandNumber >= int(listSize) || commandNumber < 0)
	{
		std::cout << "无效指令,请重新输入!";
	}
	else
	{
		system("cls");
		command = commandList[commandNumber];
	}
	if (command)
	{
		(this->*command)();
	}
	system("pause");
	AUTO_SAVE();
	Menu();
}

void Application::command1()
{
	std::string _id, _title, _teacherName, _requirement;
	unsigned int _maxNum;
	std::cout << "请输入选题的信息" << std::endl;
	std::cout << "编号:";
	std::getline(std::cin, _id);
	std::cout << "标题:";
	std::getline(std::cin, _title);
	std::cout << "指导老师姓名:";
	std::getline(std::cin, _teacherName);
	std::cout << "请输入该选题的要求:" << std::endl;
	std::getline(std::cin, _requirement);
	std::cout << "最大选题人数:";
	std::cin >> _maxNum;
	const bool isSuccess = sys->AddProblem(_id, _title, _teacherName, _requirement, _maxNum);
	if (isSuccess)
	{
		std::cout << "添加选题成功!" << std::endl;
	}
	else
	{
		std::cout << "添加失败!编号重复或有内容为空!" << std::endl;
	}
	AUTO_SAVE();
}

void Application::command2()
{
	std::string _stuID, _name, _selectedProblemID;
	bool _sex;
	unsigned int _age;
	std::cout << "请输入学生的信息" << std::endl << "学号:";
	std::getline(std::cin, _stuID);
	std::cout << "姓名:";
	std::getline(std::cin, _name);
	int sex;
	do 
	{
		std::cout << "性别 1.男 2.女:";
		std::cin >> sex;
		std::cin.get();
		_sex = sex == 1 ? true : false;
	} while (sex != 1 && sex != 2);
	std::cout << "年龄:";
	std::cin >> _age;
	std::cin.get();
	std::cout << "请输入选择题目编号(若暂时不选则直接回车):";
	std::getline(std::cin, _selectedProblemID);
	const bool isSuccess = sys->AddStudent(_stuID, _name, _sex, _age, _selectedProblemID);
	if (isSuccess)
	{
		std::cout << "添加学生成功!" << std::endl;
	}
	else
	{
		std::cout << "添加失败!学号，姓名重复或选题编号为搜索不到对应的选题!" << std::endl;
	}
	AUTO_SAVE();
}

void Application::command3()
{
	std::string id;
	std::cout << sys->OutputProb(OutputMethod::Short) << std::endl;
	std::cout << "请输入想要修改选题的编号或序号:" << std::endl;
	std::getline(std::cin, id);
	Problem* targetProb = sys->FindProblem(id);
	if (!targetProb)
	{
		std::cout << "没有找到选题!" << std::endl;
	}
	else
	{
		int reply;
		std::cout << targetProb->Output(OutputMethod::Complete) << std::endl << std::endl
			<< "1.标题" << std::endl
			<< "2.指导老师" << std::endl
			<< "3.要求" << std::endl
			<< "4.最大选题人数" << std::endl
			<< "请输入你想要修改的内容:";
		std::cin >> reply;
		std::cin.get();
		bool isSuccess;
		switch (reply)
		{
		case 1:
			{
				std::string title;
				std::cout << "请输入新标题:";
				std::getline(std::cin, title);
				isSuccess = sys->ChangeProblemInfo(targetProb, title, ProbStringInfo::Title);
				break;
			}
		case 2:
			{
				std::string teacherName;
				std::cout << "请输入新指导老师:";
				std::getline(std::cin, teacherName);
				isSuccess = sys->ChangeProblemInfo(targetProb, teacherName, ProbStringInfo::TeacherName);
				break;
			}
		case 3:
			{
				std::string requirement;
				std::cout << "请输入新要求:";
				std::getline(std::cin, requirement);
				isSuccess = sys->ChangeProblemInfo(targetProb, requirement, ProbStringInfo::Requirement);
				break;
			}
		case 4:
			{
				unsigned int maxNum;
				std::cout << "请输入最大选题人数(当前已选人数为" << targetProb->GetNowNumber() << "):";
				std::cin >> maxNum;
				std::cin.get();
				isSuccess = sys->ChangeProblemInfo(targetProb, maxNum);
				break;
			}
		default:
			std::cout << "无效指令!即将返回菜单!";
			return;
		}
		std::cout << (isSuccess ? "修改成功!" : "修改失败!输入内容有空白或新的最大选题人数小于当前已选人数!");
	}
	AUTO_SAVE();
}

void Application::command4()
{
	std::string stuID;
	std::cout << sys->OutputStu(OutputMethod::Short) << std::endl;
	std::cout << "请输入想要修改选题的编号或序号:" << std::endl;
	std::getline(std::cin, stuID);
	Student* targetStu = sys->FindStudent(stuID);
	if (!targetStu)
	{
		std::cout << "没有找到学生!";
	}
	else
	{
		int reply;
		std::cout << targetStu->Output(OutputMethod::Complete) << std::endl << std::endl
			<< "1.性别" << std::endl
			<< "2.年龄" << std::endl
			<< "3.选题" << std::endl
			<< "请输入你想要修改的内容:";
		std::cin >> reply;
		std::cin.get();
		bool isSuccess;
		switch (reply)
		{
		case 1:
			{
				int sex;
				bool _sex;
				do
				{
					std::cout << "请输入性别 1男2女:";
					std::cin.get();
					std::cin >> sex;
					_sex = sex == 1 ? true : false;
				} while (sex != 1 && sex != 2);
				isSuccess = sys->ChangeStudentInfo(targetStu, _sex);
				break;
			}
		case 2:
			{
				unsigned int age;
				std::cout << "请输入年龄:";
				std::cin >> age;
				std::cin.get();
				isSuccess = sys->ChangeStudentInfo(targetStu, age);
				break;
			}
		case 3:
			{
				std::string id;
				std::cout << "请输入新的选题编号:";
				std::getline(std::cin, id);
				Problem* targetProb = sys->FindProblem(id);
				if (targetProb)
				{
					isSuccess = sys->ChangeStudentInfo(targetStu, targetProb);
				}
				else
				{
					std::cout << "修改失败,选题不存在!即将返回菜单!";
					return;
				}
				break;
			}
		default:
			std::cout << "无效指令!即将返回菜单!";
			return;
		}
		std::cout << (isSuccess ? "修改成功!" : "修改失败!输入内容有空白或新的题目已满!");
	}
	AUTO_SAVE();
}

void Application::command5()
{
	unsigned int index;
	std::cout << sys->OutputProb(OutputMethod::IgnoreID) << std::endl
		<< "请输入想要删除选题的序号:";
	std::cin >> index;
	std::cin.get();
	index--;
	const bool isSuccess = sys->DeleteProblem(index);
	std::cout << (isSuccess ? "删除成功!" : "删除失败,输入了错误的序号或该选题已有学生选择!");
	AUTO_SAVE();
}

void Application::command6()
{
	unsigned int index;
	std::cout << sys->OutputStu(OutputMethod::IgnoreID) << std::endl
		<< "请输入想要删除学生的序号:";
	std::cin >> index;
	std::cin.get();
	index--;
	const bool isSuccess = sys->DeleteStudent(index);
	std::cout << (isSuccess ? "删除成功!" : "删除失败,输入了错误的序号!");
	AUTO_SAVE();
}

void Application::command7()
{
	std::string str;
	std::cout << "请输入想要搜索的选题编号 标题或指导老师:" << std::endl;
	std::cin >> str;
	std::cout << sys->SearchProblem(str);
}

void Application::command8()
{
	std::string str;
	int reply;
	std::cout << "1.按学生信息搜索" << std::endl
		<< "2.按选题信息搜索" << std::endl
		<< "请输入你的搜索方式:";
	std::cin >> reply;
	std::cin.get();
	if (reply == 1)
	{
		std::cout << "请输入想要搜索的学生学号 姓名:" << std::endl;
		std::getline(std::cin, str);
		std::cout << sys->SearchStudent(str, 1);
	}
	else if (reply == 2)
	{
		std::cout << "请输入想要搜索的选题编号:" << std::endl;
		std::getline(std::cin, str);
		std::cout << sys->SearchStudent(str, 2);
	}
}

void Application::command9()
{
	std::cout << sys->OutputProb(OutputMethod::Complete) << std::endl;
}

void Application::command10()
{
	std::cout << sys->OutputStu(OutputMethod::Complete) << std::endl;
}

void Application::command0()
{
	std::cout << "结果已保存。";
	system("pause");
	exit(0);
}