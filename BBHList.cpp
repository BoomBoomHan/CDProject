#include "BBHList.h"

template<typename T>
BBHList<T>::BBHList()
{
	List.assign(1);
}

template<typename T>
unsigned int BBHList<T>::GetSize()
{
	unsigned int size;
	size = List.size();
	return size;
}

template<typename T>
void BBHList<T>::AddElement(const T& element)
{
	List.push_back(element);
}

template<typename T>
void BBHList<T>::DeleteElement(unsigned int index)
{
	List.erase(index);
}