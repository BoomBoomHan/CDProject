#pragma once
#include "BBHList.h"
#include "Enums.h"


class System//�γ����ѡ��ϵͳ
{
private:
	bool isThisActive;
	static bool isSystemActive;
private:
	BBHList<class Student>* studentList;
	BBHList<class Problem>* problemList;
private:
	BBHList<Student>& stuList;
	BBHList<Problem>& probList;

public:
	//ȱʡ����
	System();
	//����
	~System();
	//ͨ��--��� ���� ָ����ʦ Ҫ�� �������--��ӿ�����Ŀ,���ҽ���ϵͳ����ʱ����,�ɹ�ʱ������
	bool AddProblem(const std::string, const std::string, const std::string, const std::string, const unsigned int);
	//ͨ��--ѧ�� ���� �Ա�(1��0Ů) ���� ѡ�����Ŀ--���ѧ��,���ҽ���ϵͳ����ʱ����,�ɹ�ʱ������
	bool AddStudent(const std::string, const std::string, const bool, const unsigned int, const Problem* = nullptr);
	//�޸�ָ������ı�š����⡢ָ����ʦ��Ҫ��,���ɹ��򷵻���
	bool ChangeProblemInfo(const Problem*, const std::string, ProbStringInfo);

	//�޸�ָ����������ѡ������,���ɹ��򷵻���
	bool ChangeProblemInfo(const Problem*, const unsigned int);
	//�޸�ָ��ѧ����ѧ�š�����,���ɹ��򷵻���
	bool ChangeStudentInfo(const Student*, const std::string, StuStringInfo);
	//�޸�ָ��ѧ�����Ա�,���ɹ��򷵻���
	bool ChangeStudentInfo(const Student*, const bool);
	//�޸�ָ��ѧ��������,���ɹ��򷵻���
	bool ChangeStudentInfo(const Student*, const unsigned int);
	//�޸�ָ��ѧ����ѡ��,���ɹ��򷵻���
	bool ChangeStudentInfo(const Student*, const Problem*);

	std::string OutputStu();
	std::string OutputProb();
};

