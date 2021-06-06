#pragma once
#include <string>

enum class OutputMethod
{
	IgnoreID,
	Short,
	Complete
};

class Problem
{
private:
	const Problem operator =(const Problem&) { return *this; }//不可赋值
	std::string id;//编号
	std::string title;//标题
	std::string teacherName;//指导老师
	std::string requirement;//要求
	unsigned int maxNum;//最大选课人数
	unsigned int nowNum;//已选人数
public:
	//编号 标题 指导老师 要求 最大人数
	Problem(const std::string, const std::string, const std::string, const std::string, const unsigned int);
	~Problem();
	//获取编号
	std::string GetID();
	//获取标题
	std::string GetTitle();
	//三种不同的输出方式,IgnoreID为只输出标题,Short为输出ID和标题,Complete为全部输出
	std::string Output(OutputMethod);
};

