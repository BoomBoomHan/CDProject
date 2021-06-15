#pragma once
#include <string>
#include "System.h"

class Student//ѧ����
{
private:
	mutable std::string stuID;//ѧ��
	mutable std::string name;//����
	mutable bool sex;//1Ϊ�У�0ΪŮ
	mutable unsigned int age;//����
	mutable class Problem* selectedProblem;//ѡ�����Ŀ
	mutable bool isDeleted;
private:
	//������Ŀ(const)
	bool setProblem(const Problem*) const;
	//������Ŀ
	//bool setProblem(const Problem*);

	//���Լ���ѡ����Ŀ��ѡ������1
	void selfDelete() const;
	friend class System;//System���Ǵ������Ԫ��
public:
	//ѧ�� ���� �Ա�(1��0Ů) ���� ѡ�����Ŀ ���
	Student(const std::string, const std::string, const bool, const unsigned int, const Problem*);
	//����
	~Student();
	//��ȡѧ��(const)
	std::string GetID() const;
	//��ȡѧ��
	//std::string GetID();
	
	//��ȡ��Ŀ(const)
	Problem* GetProblem() const;
	//��ȡ��Ŀ
	//Problem* GetProblem();
	
	//���ֲ�ͬ�������ʽ,IgnoreIDΪֻ�������,ShortΪ���ID�ͱ���,CompleteΪȫ�����,SaveΪֻ����ؼ���Ϣ
	std::string Output(OutputMethod) const;
	//������ѧ��ѧ����ͬ�򷵻���(const)
	bool operator ==(const Student&) const;
	//������ѧ��ѧ����ͬ�򷵻���
	//bool operator ==(const Student&);
	
	//����Ԫ������System��ĳ�Ա����
	friend bool System::ChangeStudentInfo(const Student*, const std::string, StuStringInfo);
	//����Ԫ������System��ĳ�Ա����
	friend bool System::ChangeStudentInfo(const Student*, const bool);
	//����Ԫ������System��ĳ�Ա����
	friend bool System::ChangeStudentInfo(const Student*, const unsigned int);
	//����Ԫ������System��ĳ�Ա����
	friend bool System::ChangeStudentInfo(const Student*, const Problem* b);
};

