#pragma once
#include <string>
#include "System.h"
#include "Enums.h"

class Problem
{
private:
	mutable std::string id;//���
	mutable std::string title;//����
	mutable std::string teacherName;//ָ����ʦ
	mutable std::string requirement;//Ҫ��
	mutable unsigned int maxNum;//���ѡ������
	mutable unsigned int nowNum;//��ѡ����
private:
	friend class Student;//Student���Ǵ������Ԫ��
public:
	//��� ���� ָ����ʦ Ҫ�� �������
	Problem(const std::string, const std::string, const std::string, const std::string, const unsigned int);
	//����
	~Problem();
	//��ȡ���(const)
	std::string GetID() const;
	//��ȡ���
	//std::string GetID();
	//��ȡ����
	std::string GetTitle();
	//��ȡ���ѡ������
	unsigned int GetMaxNumber();
	//��ȡ��ѡ����
	unsigned int GetNowNumber();
	//�Ƿ���ѡ��
	bool IsFull() const;
	//���ֲ�ͬ�������ʽ,IgnoreIDΪֻ�������,ShortΪ���ID�ͱ���,CompleteΪȫ�����
	std::string Output(OutputMethod);
	//�����߱����ͬ�򷵻���(const)
	bool operator ==(const Problem&) const;
	//�����߱����ͬ�򷵻���
	//bool operator ==(const Problem&);

	//����Ԫ������System��ĳ�Ա����
	friend bool System::ChangeProblemInfo(const Problem*, const std::string, ProbStringInfo);
	//����Ԫ������System��ĳ�Ա����
	friend bool System::ChangeProblemInfo(const Problem*, const unsigned int);
};

