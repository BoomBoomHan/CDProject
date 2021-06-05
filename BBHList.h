#pragma once
#include "Problem.h"
#include "Student.h"
#include <vector>

//由于模板类比较特殊,这个类的定义只有.h而无.cpp文件，函数的声明与定义都写在.h内
template<typename T>
struct BBHList//用于存储学生及课设题目的表单
{
	std::vector<T> List;

	BBHList()
	{
		
	}
	unsigned int GetSize()//获取表单元素的个数
	{
		unsigned int size = 0;
		size = List.size();
		return size;
	}
	void AddElement(const T& element)//在尾部添加元素
	{
		List.push_back(element);
	}
	void DeleteElement(unsigned int index)//删除指定元素
	{
		List.erase(List.begin() + index);
	}
	~BBHList()//释放所有元素
	{
		List.clear();
	}
};