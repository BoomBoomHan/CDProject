#include "Problem.h"

Problem::Problem(const std::string _id, const std::string _title, const std::string _teacherName, const std::string _requirement, const unsigned int _maxNum)
	:id(_id),
	title(_title),
	teacherName(_teacherName),
	requirement(_requirement),
	maxNum(_maxNum),
	nowNum(0)
{

}

Problem::~Problem()
{
	id = '\0';
	title = '\0';
	teacherName = '\0';
	requirement = '\0';
	maxNum = 0;
	nowNum = 0;
}

std::string Problem::GetID()
{
	return id;
}

std::string Problem::GetTitle()
{
	return title;
}