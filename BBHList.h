#pragma once
#include "Problem.h"
#include "Student.h"
#include <vector>

//����ģ����Ƚ�����,�����Ķ���ֻ��.h����.cpp�ļ��������������붨�嶼д��.h��
template<typename T>
struct BBHList//���ڴ洢ѧ����������Ŀ�ı�
{
	std::vector<T> List;

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
};