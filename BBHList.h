#pragma once
#include "FunctionLibrary.h"
#include <vector>

//����ģ����Ƚ�����,�����Ķ���ֻ��.h����.cpp�ļ��������������붨�嶼д��.h��
//���ڴ洢ѧ����������Ŀ�ı�
template<typename T>
struct BBHList
{
private:
	std::vector<T> list;//��
public:

	BBHList()
	{
		
	}

	//���沢�ͷ�����Ԫ��
	~BBHList()
	{
		list.clear();
	}

	//��ȡ��Ԫ�صĸ���
	unsigned int GetSize() const
	{
		unsigned int size = 0;
		size = (unsigned int)(list.size());
		return size;
	}

	//��β�����Ԫ��,���ɹ��򷵻���
	bool AddElement(const T& element)
	{
		const bool isUnique = CheckUnique(element);
		if (isUnique)
		{
			list.push_back(element);
		}
		return isUnique;
	}

	//ɾ��ָ��Ԫ��,���ɹ��򷵻���
	bool DeleteElement(unsigned int index)
	{
		if (!FunctionLibrary::IsInRange(index, 0u, GetSize(), true))
		{
			return false;
		}
		list.erase(list.begin() + index);
		return true;
	}

	//��ȡ��i��Ԫ��
	T& operator [](const unsigned int index)
	{
		if (FunctionLibrary::IsInRange(index, 0u, GetSize(), true))
		{
			return list[index];
		}
		return list[GetSize() - 1];
	}

	//����Ƿ�����ͬԪ��,�����򷵻���
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