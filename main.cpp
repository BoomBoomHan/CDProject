#include <list>
#include <iostream>
#include "Student.h"
#include "Problem.h"
#include "System.h"
using namespace std;

int main()
{
	//BBHList<Problem> list;
	//Problem p1("001", "�γ����ѡ��ϵͳ", "����", "��", 100);
	//Problem p2("002", "ͨѶ¼", "��ϲ��", "��", 66);
	//Problem p3("003", "��վ��Ʊϵͳ", "��׿�", "��", 90);
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
	sys->AddProblem("010", "�γ����ѡ��ϵͳ", "����", "����", 30);
	sys->AddProblem("002", "ͨѶ¼", "��ϲ��", "��", 66);
	sys->AddProblem("003", "��վ��Ʊϵͳ", "��׿�", "��", 90);
	sys->AddProblem("666", "��˼·ǩ��ϵͳ", "�쿭��", "��", 5);
	//sys->AddStudent("20210122", "����", 1, 19, "666");
	// 	   34�����ᵼ�±���
	//sys->AddStudent("20210122", "����", 1, 19, "666");
	cout << sys->OutputProb(OutputMethod::Complete);
	//cout << sys->OutputStu();
	/*Problem* p = new Problem("010", "�γ����ѡ��ϵͳ", "����", "����", 30);
	Student stu("20210122", "����", 1, 19, p);*/
}