#include <list>
#include <iostream>
#include "Student.h"
#include "Problem.h"
#include "System.h"

int main()
{
	//BBHList<Problem> list;
	//Problem p1("001", "课程设计选题系统", "艾勇", "无", 100);
	//Problem p2("002", "通讯录", "杨喜敏", "无", 66);
	//Problem p3("003", "火车站购票系统", "姜卓睿", "无", 90);
	//list.AddElement(p1);
	//list.AddElement(p2);
	//bool result = list.AddElement(p3);
	//std::cout << result << std::endl;
	//for (unsigned int i = 0; i < list.GetSize(); i++)
	//{
	//	//Problem prob = list[i];
	//	std::cout << list[i].Output(OutputMethod::Complete) << std::endl << std::endl;
	//}
	////list.DeleteElement(1);
	//for (unsigned int i = 0; i < list.GetSize(); i++)
	//{
	//	//std::cout << list[i] << std::endl;
	//}
	//return 0;
	System* sys = new System;
	sys->AddProblem("010", "课程设计选题系统", "艾勇", "暂无", 30);
	sys->AddStudent("20210122", "张三", 1, 19);
	std::cout << sys->OutputProb();
	std::cout << sys->OutputStu();
}