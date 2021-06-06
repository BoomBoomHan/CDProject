#pragma once
#include "Problem.h"
#include "Student.h"
#include "FunctionLibrary.h"
#include <vector>

//����ģ����Ƚ�����,�����Ķ���ֻ��.h����.cpp�ļ��������������붨�嶼д��.h��
template<typename T>
struct BBHList//���ڴ洢ѧ����������Ŀ�ı�
{
private:
	std::vector<T> List;

public:
	BBHList()
	{
		
	}
	unsigned int GetSize()//��ȡ��Ԫ�صĸ���
	{
		unsigned int size = 0;
		size = List.size();
		return size;
	}
	void AddElement(const T& element)//��β�����Ԫ��
	{
		List.push_back(element);
	}
	void DeleteElement(unsigned int index)//ɾ��ָ��Ԫ��
	{
		List.erase(List.begin() + index);
	}
	~BBHList()//�ͷ�����Ԫ��
	{
		List.clear();
	}
	const T operator [](unsigned int index)//��ȡһ��Ԫ��
	{
		if (FunctionLibrary::IsInRange(index, 0u, GetSize(), true))
		{
			return List[index];
		}
		return 0;
	}
};