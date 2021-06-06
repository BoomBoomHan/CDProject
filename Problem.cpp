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

std::string Problem::GetID()
{
	return id;
}

std::string Problem::GetTitle()
{
	return title;
}

std::string Problem::Output(OutputMethod method)
{
	std::string result;
	switch (method)
	{
	case OutputMethod::Complete:
		result = "���:" + id + "\n����:" + title + "\nָ����ʦ:" + teacherName + "\nҪ��:" + requirement
			+ "\n���ѡ������:" + FunctionLibrary::ToString<unsigned int>(maxNum) + "\n��ѡ����:" + FunctionLibrary::ToString<unsigned int>(nowNum);
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