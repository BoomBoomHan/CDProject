#include <list>
#include <iostream>
#include "Student.h"
#include "Problem.h"
#include "System.h"
using namespace std;

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
	sys->AddProblem("002", "通讯录", "杨喜敏", "无", 66);
	sys->AddProblem("003", "火车站购票系统", "姜卓睿", "无", 90);
	sys->AddProblem("666", "新思路签到系统", "朱凯闻", "无", 5);
	//sys->AddStudent("20210122", "张三", 1, 19, "666");
	// 	   34行语句会导致崩溃
	//sys->AddStudent("20210122", "张三", 1, 19, "666");
	cout << sys->OutputProb(OutputMethod::Complete);
	//cout << sys->OutputStu();
	/*Problem* p = new Problem("010", "课程设计选题系统", "艾勇", "暂无", 30);
	Student stu("20210122", "张三", 1, 19, p);*/
}