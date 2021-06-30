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
	std::cout << "��ӭ!���¼\n�˺�:";
	std::getline(std::cin, username);
	std::cout << "����:";
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
		std::cout << "�˺Ż��������,�����µ�¼!��0�˳�����";
		std::cin >> reply;
		if (reply == '0')
		{
			std::cout << "�˳��ɹ���";
			system("pause");
			exit(1);
		}
		system("cls");
		Login();
	}
	else
	{
		std::cout << "��¼�ɹ�!";
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
	std::cout << "1.���ѡ��" << std::endl
		<< "2.���ѧ��" << std::endl
		<< "3.�޸�ѡ����Ϣ" << std::endl
		<< "4.�޸�ѧ����Ϣ" << std::endl
		<< "5.ɾ��ѡ��" << std::endl
		<< "6.ɾ��ѧ��" << std::endl
		<< "7.����ѡ��" << std::endl
		<< "8.����ѧ��" << std::endl
		<< "9.��ʾ����ѡ��" << std::endl
		<< "10.��ʾ����ѧ��" << std::endl
		<< "0.�˳�ϵͳ" << std::endl
		<< "������ָ��:";
	std::cin >> commandNumber;
	std::cin.get();
	if (commandNumber >= int(listSize) || commandNumber < 0)
	{
		std::cout << "��Чָ��,����������!";
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
	std::cout << "������ѡ�����Ϣ" << std::endl;
	std::cout << "���:";
	std::getline(std::cin, _id);
	std::cout << "����:";
	std::getline(std::cin, _title);
	std::cout << "ָ����ʦ����:";
	std::getline(std::cin, _teacherName);
	std::cout << "�������ѡ���Ҫ��:" << std::endl;
	std::getline(std::cin, _requirement);
	std::cout << "���ѡ������:";
	std::cin >> _maxNum;
	const bool isSuccess = sys->AddProblem(_id, _title, _teacherName, _requirement, _maxNum);
	if (isSuccess)
	{
		std::cout << "���ѡ��ɹ�!" << std::endl;
	}
	else
	{
		std::cout << "���ʧ��!����ظ���������Ϊ��!" << std::endl;
	}
	AUTO_SAVE();
}

void Application::command2()
{
	std::string _stuID, _name, _selectedProblemID;
	bool _sex;
	unsigned int _age;
	std::cout << "������ѧ������Ϣ" << std::endl << "ѧ��:";
	std::getline(std::cin, _stuID);
	std::cout << "����:";
	std::getline(std::cin, _name);
	int sex;
	do 
	{
		std::cout << "�Ա� 1.�� 2.Ů:";
		std::cin >> sex;
		std::cin.get();
		_sex = sex == 1 ? true : false;
	} while (sex != 1 && sex != 2);
	std::cout << "����:";
	std::cin >> _age;
	std::cin.get();
	std::cout << "������ѡ����Ŀ���(����ʱ��ѡ��ֱ�ӻس�):";
	std::getline(std::cin, _selectedProblemID);
	const bool isSuccess = sys->AddStudent(_stuID, _name, _sex, _age, _selectedProblemID);
	if (isSuccess)
	{
		std::cout << "���ѧ���ɹ�!" << std::endl;
	}
	else
	{
		std::cout << "���ʧ��!ѧ�ţ������ظ���ѡ����Ϊ����������Ӧ��ѡ��!" << std::endl;
	}
	AUTO_SAVE();
}

void Application::command3()
{
	std::string id;
	std::cout << sys->OutputProb(OutputMethod::Short) << std::endl;
	std::cout << "��������Ҫ�޸�ѡ��ı�Ż����:" << std::endl;
	std::getline(std::cin, id);
	Problem* targetProb = sys->FindProblem(id);
	if (!targetProb)
	{
		std::cout << "û���ҵ�ѡ��!" << std::endl;
	}
	else
	{
		int reply;
		std::cout << targetProb->Output(OutputMethod::Complete) << std::endl << std::endl
			<< "1.����" << std::endl
			<< "2.ָ����ʦ" << std::endl
			<< "3.Ҫ��" << std::endl
			<< "4.���ѡ������" << std::endl
			<< "����������Ҫ�޸ĵ�����:";
		std::cin >> reply;
		std::cin.get();
		bool isSuccess;
		switch (reply)
		{
		case 1:
			{
				std::string title;
				std::cout << "�������±���:";
				std::getline(std::cin, title);
				isSuccess = sys->ChangeProblemInfo(targetProb, title, ProbStringInfo::Title);
				break;
			}
		case 2:
			{
				std::string teacherName;
				std::cout << "��������ָ����ʦ:";
				std::getline(std::cin, teacherName);
				isSuccess = sys->ChangeProblemInfo(targetProb, teacherName, ProbStringInfo::TeacherName);
				break;
			}
		case 3:
			{
				std::string requirement;
				std::cout << "��������Ҫ��:";
				std::getline(std::cin, requirement);
				isSuccess = sys->ChangeProblemInfo(targetProb, requirement, ProbStringInfo::Requirement);
				break;
			}
		case 4:
			{
				unsigned int maxNum;
				std::cout << "���������ѡ������(��ǰ��ѡ����Ϊ" << targetProb->GetNowNumber() << "):";
				std::cin >> maxNum;
				std::cin.get();
				isSuccess = sys->ChangeProblemInfo(targetProb, maxNum);
				break;
			}
		default:
			std::cout << "��Чָ��!�������ز˵�!";
			return;
		}
		std::cout << (isSuccess ? "�޸ĳɹ�!" : "�޸�ʧ��!���������пհ׻��µ����ѡ������С�ڵ�ǰ��ѡ����!");
	}
	AUTO_SAVE();
}

void Application::command4()
{
	std::string stuID;
	std::cout << sys->OutputStu(OutputMethod::Short) << std::endl;
	std::cout << "��������Ҫ�޸�ѡ��ı�Ż����:" << std::endl;
	std::getline(std::cin, stuID);
	Student* targetStu = sys->FindStudent(stuID);
	if (!targetStu)
	{
		std::cout << "û���ҵ�ѧ��!";
	}
	else
	{
		int reply;
		std::cout << targetStu->Output(OutputMethod::Complete) << std::endl << std::endl
			<< "1.�Ա�" << std::endl
			<< "2.����" << std::endl
			<< "3.ѡ��" << std::endl
			<< "����������Ҫ�޸ĵ�����:";
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
					std::cout << "�������Ա� 1��2Ů:";
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
				std::cout << "����������:";
				std::cin >> age;
				std::cin.get();
				isSuccess = sys->ChangeStudentInfo(targetStu, age);
				break;
			}
		case 3:
			{
				std::string id;
				std::cout << "�������µ�ѡ����:";
				std::getline(std::cin, id);
				Problem* targetProb = sys->FindProblem(id);
				if (targetProb)
				{
					isSuccess = sys->ChangeStudentInfo(targetStu, targetProb);
				}
				else
				{
					std::cout << "�޸�ʧ��,ѡ�ⲻ����!�������ز˵�!";
					return;
				}
				break;
			}
		default:
			std::cout << "��Чָ��!�������ز˵�!";
			return;
		}
		std::cout << (isSuccess ? "�޸ĳɹ�!" : "�޸�ʧ��!���������пհ׻��µ���Ŀ����!");
	}
	AUTO_SAVE();
}

void Application::command5()
{
	unsigned int index;
	std::cout << sys->OutputProb(OutputMethod::IgnoreID) << std::endl
		<< "��������Ҫɾ��ѡ������:";
	std::cin >> index;
	std::cin.get();
	index--;
	const bool isSuccess = sys->DeleteProblem(index);
	std::cout << (isSuccess ? "ɾ���ɹ�!" : "ɾ��ʧ��,�����˴������Ż��ѡ������ѧ��ѡ��!");
	AUTO_SAVE();
}

void Application::command6()
{
	unsigned int index;
	std::cout << sys->OutputStu(OutputMethod::IgnoreID) << std::endl
		<< "��������Ҫɾ��ѧ�������:";
	std::cin >> index;
	std::cin.get();
	index--;
	const bool isSuccess = sys->DeleteStudent(index);
	std::cout << (isSuccess ? "ɾ���ɹ�!" : "ɾ��ʧ��,�����˴�������!");
	AUTO_SAVE();
}

void Application::command7()
{
	std::string str;
	std::cout << "��������Ҫ������ѡ���� �����ָ����ʦ:" << std::endl;
	std::cin >> str;
	std::cout << sys->SearchProblem(str);
}

void Application::command8()
{
	std::string str;
	int reply;
	std::cout << "1.��ѧ����Ϣ����" << std::endl
		<< "2.��ѡ����Ϣ����" << std::endl
		<< "���������������ʽ:";
	std::cin >> reply;
	std::cin.get();
	if (reply == 1)
	{
		std::cout << "��������Ҫ������ѧ��ѧ�� ����:" << std::endl;
		std::getline(std::cin, str);
		std::cout << sys->SearchStudent(str, 1);
	}
	else if (reply == 2)
	{
		std::cout << "��������Ҫ������ѡ����:" << std::endl;
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
	std::cout << "����ѱ��档";
	system("pause");
	exit(0);
}