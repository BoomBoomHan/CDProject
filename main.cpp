#include <list>
#include <iostream>
#include "BBHList.h"
#include "Student.h"
#include "Problem.h"

int main()
{
	BBHList<Problem> list;
	Problem p1("001", "�γ����ѡ��ϵͳ", "����", "��", 100);
	Problem p2("002", "ͨѶ¼", "��ϲ��", "��", 66);
	list.AddElement(p1);
	list.AddElement(p2);
	for (unsigned int i = 0; i < list.GetSize(); i++)
	{
		//Problem prob = list[i];
		std::cout << list[i].Output(OutputMethod::Complete) << std::endl << std::endl;
	}
	//list.DeleteElement(1);
	for (unsigned int i = 0; i < list.GetSize(); i++)
	{
		//std::cout << list[i] << std::endl;
	}
	return 0;
}