#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "System.h"

class Application
{
private:
	System* sys;//内置系统
	//添加选题
	void command1();
	//添加学生
	void command2();
	//修改选题信息
	void command3();
	//修改学生信息
	void command4();
	//删除选题
	void command5();
	//删除学生
	void command6();
	//搜索选题
	void command7();
	//搜索学生
	void command8();
	//显示所有选题
	void command9();
	//显示所有学生
	void command10();
	//退出系统
	void command0();
	//指令函数指针
	void (Application::* command)();
	//指令函数指针表单
	BBHList<void (Application::*)()> commandList;
public:
	//构造函数
	Application();
	//析构函数
	~Application();
	//初始化
	void Login();
	//菜单
	void Menu();
};

