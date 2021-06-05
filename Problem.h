#pragma once
#include <string>

class Problem
{
private:
	Problem(const Problem&);//不可拷贝
	const Problem operator =(const Problem&) { return *this; }//不可赋值
	std::string id;
	std::string title;
	std::string teacherName;
	std::string requirement;
	unsigned int maxNum;
	unsigned int nowNum;
public:
	Problem(const std::string, const std::string, const std::string, const std::string, const unsigned int);
	~Problem();
	std::string GetID();
	std::string GetTitle();
};

