#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "System.h"

class Application
{
private:
	System* sys;//����ϵͳ
	//���ѡ��
	void command1();
	//���ѧ��
	void command2();
	//�޸�ѡ����Ϣ
	void command3();
	//�޸�ѧ����Ϣ
	void command4();
	//ɾ��ѡ��
	void command5();
	//ɾ��ѧ��
	void command6();
	//����ѡ��
	void command7();
	//����ѧ��
	void command8();
	//��ʾ����ѡ��
	void command9();
	//��ʾ����ѧ��
	void command10();
	//�˳�ϵͳ
	void command0();
	//ָ���ָ��
	void (Application::* command)();
	//ָ���ָ���
	BBHList<void (Application::*)()> commandList;
public:
	//���캯��
	Application();
	//��������
	~Application();
	//��ʼ��
	void Login();
	//�˵�
	void Menu();
};

