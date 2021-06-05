#pragma once
#include <string>

class Problem
{
private:
	Problem(const Problem&);//���ɿ���
	const Problem operator =(const Problem&) { return *this; }//���ɸ�ֵ
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

