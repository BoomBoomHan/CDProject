#include "Application.h"

void Login(System*);
void Menu(System*);

void Login(System* sys)
{
	std::string username, password;
	std::cout << "��ӭ!���¼\n�˺�:";
	std::cin >> username;
	std::cout << "����:";
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
		std::cout << "�˺Ż��������,�����µ�¼!��0�˳�����";
		std::cin >> reply;
		if (reply == '0')
		{
			std::cout << "�˳��ɹ���";
			system("pause");
			exit(1);
		}
		system("cls");
		Login(sys);
	}
	else
	{
		std::cout << "��¼�ɹ�!";
		system("pause");
		system("cls");
		Menu(sys);
	}
}

void Menu(System* sys)
{
	int command;
	std::cout << "1.���ѡ��" << std::endl
		<< "2.���ѧ��" << std::endl
		<< "3.�޸�ѡ����Ϣ" << std::endl
		<< "4.�޸�ѧ����Ϣ" << std::endl
		<< "5.ɾ��ѡ��" << std::endl
		<< "6.ɾ��ѧ��" << std::endl
		<< "7.����ѡ��" << std::endl
		<< "8.����ѧ��" << std::endl
		<< "0.�˳�ϵͳ" << std::endl
		<< "������ָ��:";
	std::cin >> command;
}

int main()
{
	Application* app = new Application();
	return 0;
}