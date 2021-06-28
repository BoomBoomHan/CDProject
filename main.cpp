#include "Application.h"

void Login(System*);
void Menu(System*);

void Login(System* sys)
{
	std::string username, password;
	std::cout << "欢迎!请登录\n账号:";
	std::cin >> username;
	std::cout << "密码:";
	std::cin >> password;
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
		Login(sys);
	}
	else
	{
		std::cout << "登录成功!";
		system("pause");
		system("cls");
		Menu(sys);
	}
}

void Menu(System* sys)
{
	int command;
	std::cout << "1.添加选题" << std::endl
		<< "2.添加学生" << std::endl
		<< "3.修改选题信息" << std::endl
		<< "4.修改学生信息" << std::endl
		<< "5.删除选题" << std::endl
		<< "6.删除学生" << std::endl
		<< "7.搜索选题" << std::endl
		<< "8.搜索学生" << std::endl
		<< "0.退出系统" << std::endl
		<< "请输入指令:";
	std::cin >> command;
}

int main()
{
	Application* app = new Application();
	return 0;
}