#include <list>
#include <iostream>
#include "BBHList.h"
#include "Student.h"
#include "Problem.h"

int main()
{
	BBHList<Problem> list;
	Problem p1("001", "课程设计选题系统", "艾勇", "无", 100);
	Problem p2("002", "通讯录", "杨喜敏", "无", 66);
	Problem p3("003", "火车站购票系统", "姜卓睿", "无", 90);
	list.AddElement(p1);
	list.AddElement(p2);
	bool result = list.AddElement(p3);
	std::cout << result << std::endl;
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