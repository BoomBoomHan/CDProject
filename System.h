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

public:
	//ȱʡ����
	System();
	//����
	~System();
	//ͨ��--��� ���� ָ����ʦ Ҫ�� �������--��ӿ�����Ŀ,���ҽ���ϵͳ����ʱ����,�ɹ�ʱ������
	bool AddProblem(const std::string, const std::string, const std::string, const std::string, const unsigned int);
	//ͨ��--ѧ�� ���� �Ա�(1��0Ů) ���� ѡ�����Ŀ--���ѧ��,���ҽ���ϵͳ����ʱ����,�ɹ�ʱ������
	bool AddStudent(const std::string, const std::string, const bool, const unsigned int, const Problem* = nullptr);
	//�޸�ָ���������Ϣ,���ɹ��򷵻���
	bool ChangeProblemInfo(const Problem*, const std::string, ProbStringInfo);
	bool ChangeProblemInfo(const Problem*, const unsigned int);
	bool ChangeProblemInfo(const Student&, const Problem*);
	//�޸�ָ��ѧ������Ϣ
	bool ChangeStudentInfo(const Student&, const std::string, StuStringInfo);
	bool ChangeStudentInfo(const Student&, const bool);
	bool ChangeStudentInfo(const Student&, const unsigned int);
	bool ChangeStudentInfo(const Student&, const Problem*);

	std::string OutputStu();
	std::string OutputProb();
};

