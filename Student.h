#pragma once
#include <string>

class Student
{
private:
	//���ɿ���
	Student(const Student&);
	//���ɸ�ֵ
	const Student operator =(const Student&) { return *this; }
	std::string stuID;//ѧ��
	std::string name;//����
	bool sex;//1Ϊ�У�0ΪŮ
	unsigned int age;//����
	mutable class Problem* selectedProblem;//ѡ�����Ŀ
public:
	//ѧ�� ���� �Ա�(1��0Ů) ���� ѡ�����Ŀ
	Student(const std::string, const std::string, const bool, const unsigned int, const Problem*);
	//����
	~Student();
	//��ȡѧ��(const)
	std::string GetID() const;
	//��ȡѧ��
	std::string GetID();
	//��ȡ��Ŀ(const)
	Problem* GetProblem() const;
	//��ȡ��Ŀ
	Problem* GetProblem();
	//������Ŀ(const)
	bool SetProblem(const Problem*) const;
	//������Ŀ
	bool SetProblem(const Problem*);
	//���Ϊ�ַ���
	std::string Output();
	//������ѧ��ѧ����ͬ�򷵻���(const)
	bool operator ==(const Student&) const;
	//������ѧ��ѧ����ͬ�򷵻���
	bool operator ==(const Student&);
};

