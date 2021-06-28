#pragma once
#include "BBHList.h"
#include "Enums.h"

class System//�γ����ѡ��ϵͳ��
{
private:
	bool isThisActive;//��ϵͳ�Ƿ񼤻�
	static bool isSystemActive;//�Ƿ���ϵͳ����
	const std::string databasePath;//���ݿ�·��
	const std::string stuListFileName;//ѧ�����ݿ��ļ���
	const std::string probListFileName;//��Ŀ���ݿ��ļ���
	const std::string correspondingAccount[2];
private:
	BBHList<class Student>* studentList;//���ѧ���ı�
	BBHList<class Problem>* problemList;//�����Ŀ�ı�
	BBHList<Student>& stuList;//studentList����
	BBHList<Problem>& probList;//problemList����
private:
	//���ݱ��Ƿ��޸Ĺ�,���������޸��Ӷ�������ѧ����ѡ�����Ŀ����ѡ��������
	void ERROR_SELF_REPAIR();
	//ɾ�����е�����
	void CLEAR_DATAS();
public:
	//���캯��,�������˺�������ȷ���������Ѽ���ϵͳʱ���ܼ���ϵͳ
	System(const std::string, const std::string);
	//��������,���沢�ͷ�����Ԫ��
	~System();
	//�������и���
	void Save();

	//ͨ��--��� ���� ָ����ʦ Ҫ�� ������� ��ѡ����--��ӿ�����Ŀ,���ҽ���ϵͳ����ʱ����,�ɹ�ʱ������
	bool AddProblem(const std::string, const std::string, const std::string, const std::string, const unsigned int, const unsigned int = 0u);
	//ͨ��--ѧ�� ���� �Ա�(1��0Ů) ���� ѡ�����Ŀ���--���ѧ��,���ҽ���ϵͳ����ʱ����,�ɹ�ʱ������
	bool AddStudent(const std::string, const std::string, const bool, const unsigned int, const std::string = "");
	//ͨ��--ѧ�� ���� �Ա�(1��0Ů) ���� ��Ŀ�б�����--���ѧ��,���ҽ���ϵͳ����ʱ����,�ɹ�ʱ������
	bool AddStudent(const std::string, const std::string, const bool, const unsigned int, const unsigned int);
	
	//�޸�ָ������ı�š����⡢ָ����ʦ��Ҫ��,���ҽ���ϵͳ����ʱ����,���ɹ��򷵻���
	bool ChangeProblemInfo(const Problem*, const std::string, ProbStringInfo);
	//�޸�ָ����������ѡ������,���ҽ���ϵͳ����ʱ����,���ɹ��򷵻���
	bool ChangeProblemInfo(const Problem*, const unsigned int);
	//���ݱ�Ż��Ŀ��ѡ��,���ҽ���ϵͳ����ʱ����
	Problem* FindProblem(const std::string);
	//�������б��е�˳����Ŀ��ѡ��,���ҽ���ϵͳ����ʱ����
	Problem* FindProblem(const unsigned int);
	//ɾ��ѡ��,��������Ѿ���ѧ��ѡ������ɾ��,���ҽ���ϵͳ����ʱ����,���ɹ��򷵻���
	bool DeleteProblem(const Problem*);
	//�����б��е�˳��ɾ��ѡ��,��������Ѿ���ѧ��ѡ������ɾ��,���ҽ���ϵͳ����ʱ����,���ɹ��򷵻���
	bool DeleteProblem(const unsigned int);

	//�޸�ָ��ѧ����ѧ�š�����,���ҽ���ϵͳ����ʱ����,���ɹ��򷵻���
	bool ChangeStudentInfo(const Student*, const std::string, StuStringInfo);
	//�޸�ָ��ѧ�����Ա�,���ҽ���ϵͳ����ʱ����,���ɹ��򷵻���
	bool ChangeStudentInfo(const Student*, const bool);
	//�޸�ָ��ѧ��������,���ҽ���ϵͳ����ʱ����,���ɹ��򷵻���
	bool ChangeStudentInfo(const Student*, const unsigned int);
	//�޸�ָ��ѧ����ѡ��,���ҽ���ϵͳ����ʱ����,���ɹ��򷵻���
	bool ChangeStudentInfo(const Student*, const Problem*);
	//����ѧ�Ż�ö�Ӧѧ��,���ҽ���ϵͳ����ʱ����
	Student* FindStudent(const std::string);
	//�����б��е�˳���ö�Ӧѧ��,���ҽ���ϵͳ����ʱ����
	Student* FindStudent(const unsigned int);
	//ɾ��ѧ��,���ҽ���ϵͳ����ʱ����,���ɹ��򷵻���
	bool DeleteStudent(const Student*);
	//�����б��е�˳��ɾ��ѧ��,���ҽ���ϵͳ����ʱ����,���ɹ��򷵻���
	bool DeleteStudent(const unsigned int);

	//����--��� ���� ָ����ʦ����--����ѡ��,���ҽ���ϵͳ����ʱ����������,����ֵΪѡ��ı���
	std::string SearchProblem(const std::string);
	//����--ѧ�� ���� ѡ������ı��--����ѧ��,���ҽ���ϵͳ����ʱ����������,����ֵΪѧ��������
	std::string SearchStudent(const std::string, const int);
	//���ѧ���б�,���ҽ���ϵͳ����ʱ����
	std::string OutputStu(OutputMethod);
	//���ѡ���б�,���ҽ���ϵͳ����ʱ����
	std::string OutputProb(OutputMethod);
	//��ȡ��ϵͳ�Ƿ񼤻�
	bool IsThisActive();
};