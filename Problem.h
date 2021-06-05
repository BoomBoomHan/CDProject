#pragma once
#include <string>

enum class OutputMethod
{
	Short,
	Complete
};

class Problem
{
private:
	Problem(const Problem&);//不可拷贝
	const Problem operator =(const Problem&) { return *this; }//不可赋值
	std::string id;//编号
	std::string title;//标题
	std::string teacherName;//指导老师
	std::string requirement;//要求
	unsigned int maxNum;//最大选课人数
	unsigned int nowNum;//已选人数
public:
	Problem(const std::string, const std::string, const std::string, const std::string, const unsigned int);
	~Problem();
	std::string GetID();//获取编号
	std::string GetTitle();//获取标题
	std::string Output(OutputMethod);//两种不同的输出方式,Short为只输出标题,Complete为全部输出
};

