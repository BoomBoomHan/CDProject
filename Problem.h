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
	Problem(const Problem&);//���ɿ���
	const Problem operator =(const Problem&) { return *this; }//���ɸ�ֵ
	std::string id;//���
	std::string title;//����
	std::string teacherName;//ָ����ʦ
	std::string requirement;//Ҫ��
	unsigned int maxNum;//���ѡ������
	unsigned int nowNum;//��ѡ����
public:
	Problem(const std::string, const std::string, const std::string, const std::string, const unsigned int);
	~Problem();
	std::string GetID();//��ȡ���
	std::string GetTitle();//��ȡ����
	std::string Output(OutputMethod);//���ֲ�ͬ�������ʽ,ShortΪֻ�������,CompleteΪȫ�����
};

