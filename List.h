#pragma once
#include "Problem.h"
#include <vector>

template<typename T>
struct List
{
	std::vector<T> List;
	
	void AddOnHead(const T&);
	void AddOnTail(const T&);
	void Delete(int index);
};


