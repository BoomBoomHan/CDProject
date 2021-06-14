#pragma once
#include "FunctionLibrary.h"
#include <vector>

//由于模板类比较特殊,这个类的定义只有.h而无.cpp文件，函数的声明与定义都写在.h内
//用于存储学生及课设题目的表单
template<typename T>
struct BBHList
{
private:
	std::vector<T> list;//表单
public:

	BBHList()
	{
		
	}

	//保存并释放所有元素
	~BBHList()
	{
		list.clear();
	}

	//获取表单元素的个数
	unsigned int GetSize() const
	{
		unsigned int size = 0;
		size = (unsigned int)(list.size());
		return size;
	}

	//在尾部添加元素,若成功则返回真
	bool AddElement(const T& element)
	{
		const bool isUnique = CheckUnique(element);
		if (isUnique)
		{
			list.push_back(element);
		}
		return isUnique;
	}

	//删除指定元素,若成功则返回真
	bool DeleteElement(unsigned int index)
	{
		if (!FunctionLibrary::IsInRange(index, 0u, GetSize(), true))
		{
			return false;
		}
		list.erase(list.begin() + index);
		return true;
	}

	//获取第i个元素
	T& operator [](const unsigned int index)
	{
		if (FunctionLibrary::IsInRange(index, 0u, GetSize(), true))
		{
			return list[index];
		}
		return list[GetSize() - 1];
	}

	//检查是否有相同元素,若无则返回真
	bool CheckUnique(const T& element) const
	{
		for (unsigned int i = 0; i < GetSize(); i++)
		{
			if (element == list[i])
			{
				return false;
			}
		}
		return true;
	}
};