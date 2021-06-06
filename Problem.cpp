#include "Problem.h"
#include "FunctionLibrary.h"

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

std::string Problem::GetID() const
{
	return id;
}

std::string Problem::GetID()
{
	return id;
}

std::string Problem::GetTitle()
{
	return title;
}

unsigned int Problem::GetMaxNumber()
{
	return maxNum;
}

unsigned int Problem::GetNowNumber()
{
	return nowNum;
}

std::string Problem::Output(OutputMethod method)
{
	std::string result;
	switch (method)
	{
	case OutputMethod::Complete:
		result = "编号:" + id + "\n标题:" + title + "\n指导老师:" + teacherName + "\n要求:" + requirement
			+ "\n最大选题人数:" + FunctionLibrary::ToString<unsigned int>(maxNum) + "\n已选人数:" + FunctionLibrary::ToString<unsigned int>(nowNum);
		break;
	case OutputMethod::IgnoreID:
		result = id + ".";
	case OutputMethod::Short:
	default:
		result += title;
		break;
	}
	return result;
}

bool Problem::operator ==(const Problem& prob) const
{
	return (id == prob.GetID()) ? true : false;
}

bool Problem::operator ==(const Problem& prob)
{
	return (id == prob.GetID()) ? true : false;
}