#pragma once
#include <string>

class Problem
{
private:
	Problem(const Problem&);//���ɿ���
	const Problem operator =(const Problem&) { return *this; }//���ɸ�ֵ
	unsigned int id;
	std::string title;
	std::string teacherName;
	std::string requirement;
	unsigned int maxNum;
	unsigned int num;
public:
	Problem(const unsigned int, const std::string, const std::string, const std::string, const unsigned int, const unsigned int = 0);
	~Problem();
};

