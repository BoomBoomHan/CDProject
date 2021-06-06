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
	const Problem operator =(const Problem&) { return *this; }//���ɸ�ֵ
	std::string id;//���
	std::string title;//����
	std::string teacherName;//ָ����ʦ
	std::string requirement;//Ҫ��
	unsigned int maxNum;//���ѡ������
	unsigned int nowNum;//��ѡ����
public:
	//��� ���� ָ����ʦ Ҫ�� �������
	Problem(const std::string, const std::string, const std::string, const std::string, const unsigned int);
	~Problem();
	//��ȡ���
	std::string GetID();
	//��ȡ����
	std::string GetTitle();
	//���ֲ�ͬ�������ʽ,IgnoreIDΪֻ�������,ShortΪ���ID�ͱ���,CompleteΪȫ�����
	std::string Output(OutputMethod);
};

