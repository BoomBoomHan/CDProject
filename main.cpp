#include <list>
#include <iostream>
#include "BBHList.h"
#include "Student.h"
#include "Problem.h"

int main()
{
	BBHList<double> list;
	list.AddElement(3.14);
	list.AddElement(2.14);
	list.AddElement(6.14);
	for (unsigned int i = 0; i < list.GetSize(); i++)
	{
		std::cout << list[i] << std::endl;
	}
	list.DeleteElement(1);
	for (unsigned int i = 0; i < list.GetSize(); i++)
	{
		std::cout << list[i] << std::endl;
	}
	return 0;
}