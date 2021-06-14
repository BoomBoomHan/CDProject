#pragma once
#include "BBHList.h"
#include "Enums.h"

class System//�γ����ѡ��ϵͳ��
{
private:
	bool isThisActive;
	static bool isSystemActive;
private:
	BBHList<class Student>* studentList;
	BBHList<class Problem>* problemList;
	BBHList<Student>& stuList;
	BBHList<Problem>& probList;
public:
	//ȱʡ����
	System();
	//��������,���沢�ͷ�����Ԫ��
	~System();

	//ͨ��--��� ���� ָ����ʦ Ҫ�� �������--��ӿ�����Ŀ,���ҽ���ϵͳ����ʱ����,�ɹ�ʱ������
	bool AddProblem(const std::string, const std::string, const std::string, const std::string, const unsigned int);
	//ͨ��--ѧ�� ���� �Ա�(1��0Ů) ���� ѡ�����Ŀ���--���ѧ��,���ҽ���ϵͳ����ʱ����,�ɹ�ʱ������
	bool AddStudent(const std::string, const std::string, const bool, const unsigned int, const std::string = "");
	//ͨ��--ѧ�� ���� �Ա�(1��0Ů) ���� ��Ŀ�б�����--���ѧ��,���ҽ���ϵͳ����ʱ����,�ɹ�ʱ������
	bool AddStudent(const std::string, const std::string, const bool, const unsigned int, const unsigned int);
	
	//�޸�ָ������ı�š����⡢ָ����ʦ��Ҫ��,���ҽ���ϵͳ����ʱ����,���ɹ��򷵻���
	bool ChangeProblemInfo(const Problem*, const std::string, ProbStringInfo);
	//�޸�ָ����������ѡ������,���ҽ���ϵͳ����ʱ����,���ɹ��򷵻���
	bool ChangeProblemInfo(const Problem*, const unsigned int);
	//ɾ��ѡ��,��������Ѿ���ѧ��ѡ������ɾ��,���ҽ���ϵͳ����ʱ����,���ɹ��򷵻���
	bool DeleteProblem(const Problem*);//δ���

	//�޸�ָ��ѧ����ѧ�š�����,���ҽ���ϵͳ����ʱ����,���ɹ��򷵻���
	bool ChangeStudentInfo(const Student*, const std::string, StuStringInfo);
	//�޸�ָ��ѧ�����Ա�,���ҽ���ϵͳ����ʱ����,���ɹ��򷵻���
	bool ChangeStudentInfo(const Student*, const bool);
	//�޸�ָ��ѧ��������,���ҽ���ϵͳ����ʱ����,���ɹ��򷵻���
	bool ChangeStudentInfo(const Student*, const unsigned int);
	//�޸�ָ��ѧ����ѡ��,���ҽ���ϵͳ����ʱ����,���ɹ��򷵻���
	bool ChangeStudentInfo(const Student*, const Problem*);
	//ɾ��ѧ��,���ҽ���ϵͳ����ʱ����,���ɹ��򷵻���
	bool DeleteStudent(const Student*);//δ���

	std::string OutputStu();
	std::string OutputProb(OutputMethod);
	void Test();
};

