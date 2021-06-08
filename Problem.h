#pragma once
#include <string>
#include "Student.h"
#include "Enums.h"

class Problem
{
private:
	//���ɸ�ֵ
	const Problem operator =(const Problem&) { return *this; }
	mutable std::string id;//���
	mutable std::string title;//����
	mutable std::string teacherName;//ָ����ʦ
	mutable std::string requirement;//Ҫ��
	mutable unsigned int maxNum;//���ѡ������
	mutable unsigned int nowNum;//��ѡ����
public:
	//��� ���� ָ����ʦ Ҫ�� �������
	Problem(const std::string, const std::string, const std::string, const std::string, const unsigned int);
	//����
	~Problem();
	//��ȡ���(const)
	std::string GetID() const;
	//��ȡ���
	std::string GetID();
	//��ȡ����
	std::string GetTitle();
	//��ȡ���ѡ������
	unsigned int GetMaxNumber();
	//��ȡ��ѡ����
	unsigned int GetNowNumber();
	//���ֲ�ͬ�������ʽ,IgnoreIDΪֻ�������,ShortΪ���ID�ͱ���,CompleteΪȫ�����
	std::string Output(OutputMethod);
	//�����߱����ͬ�򷵻���(const)
	bool operator ==(const Problem&) const;
	//�����߱����ͬ�򷵻���
	bool operator ==(const Problem&);
	//����Ԫ������Student��ĳ�Ա����const�汾
	friend bool Student::SetProblem(const Problem*) const;
	//����Ԫ������Student��ĳ�Ա����
	friend bool Student::SetProblem(const Problem*);
};

