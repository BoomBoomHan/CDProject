#pragma once
#include "Problem.h"
#include <vector>

template<typename T>
struct BBHList
{
	std::vector<T> List;

	BBHList();
	unsigned int GetSize();
	void AddElement(const T&);
	void DeleteElement(unsigned int);
};