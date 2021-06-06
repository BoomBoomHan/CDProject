#pragma once
#include "Problem.h"
#include "Student.h"
#include "FunctionLibrary.h"
#include <vector>

//由于模板类比较特殊,这个类的定义只有.h而无.cpp文件，函数的声明与定义都写在.h内
template<typename T>
struct BBHList//用于存储学生及课设题目的表单
{
private:
	std::vector<T> List;//表单

public:
	BBHList()
	{
		
	}

	//获取表单元素的个数
	unsigned int GetSize()
	{
		unsigned int size = 0;
		size = List.size();
		return size;
	}

	//在尾部添加元素
	void AddElement(const T& element)
	{
		List.push_back(element);
	}

	//删除指定元素
	void DeleteElement(unsigned int index)
	{
		List.erase(List.begin() + index);
	}

	//保存并释放所有元素
	~BBHList()
	{
		List.clear();
	}

	//获取第i个元素
	T& operator [](const unsigned int index)
	{
		if (FunctionLibrary::IsInRange(index, 0u, GetSize() - 1, true))
		{
			return List[index];
		}
		return List[0];
	}
};