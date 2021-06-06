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
	std::vector<T> List;//��

public:
	BBHList()
	{
		
	}

	//��ȡ��Ԫ�صĸ���
	unsigned int GetSize()
	{
		unsigned int size = 0;
		size = List.size();
		return size;
	}

	//��β�����Ԫ��
	void AddElement(const T& element)
	{
		List.push_back(element);
	}

	//ɾ��ָ��Ԫ��
	void DeleteElement(unsigned int index)
	{
		List.erase(List.begin() + index);
	}

	//���沢�ͷ�����Ԫ��
	~BBHList()
	{
		List.clear();
	}

	//��ȡ��i��Ԫ��
	T& operator [](const unsigned int index)
	{
		if (FunctionLibrary::IsInRange(index, 0u, GetSize() - 1, true))
		{
			return List[index];
		}
		return List[0];
	}
};