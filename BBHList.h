#pragma once
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
		size = (unsigned int)(List.size());
		return size;
	}

	//��β�����Ԫ��,���ɹ��򷵻���
	bool AddElement(const T& element)
	{
		const bool isUnique = CheckUnique(element);
		if (isUnique)
		{
			List.push_back(element);
		}
		return isUnique;
	}

	//ɾ��ָ��Ԫ��,���ɹ��򷵻���
	bool DeleteElement(unsigned int index)
	{
		if (!FunctionLibrary::IsInRange(index, 0u, GetSize() - 1, true))
		{
			return false;
		}
		List.erase(List.begin() + index);
		return true;
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

	//����Ƿ�����ͬԪ��,�����򷵻���
	bool CheckUnique(const T& element)
	{
		for (unsigned int i = 0; i < GetSize(); i++)
		{
			if (element == List[i])
			{
				return false;
			}
		}
		return true;
	}
};