#pragma once
#include "BBHList.h"
#include "Student.h"
#include "Problem.h"

class System//�γ����ѡ��ϵͳ
{
private:
	bool isThisActive;
	static bool isSystemActive;
private:
	BBHList<Student>* studentList;
	BBHList<Problem>* problemList;

public:
	//ȱʡ����
	System();
	//����
	~System();
	//ͨ��--��� ���� ָ����ʦ Ҫ�� �������--��ӿ�����Ŀ,���ҽ���ϵͳ����ʱ����,�ɹ�ʱ������
	bool AddProblem(const std::string, const std::string, const std::string, const std::string, const unsigned int);
	//ͨ��--ѧ�� ���� �Ա�(1��0Ů) ���� ѡ�����Ŀ--���ѧ��,���ҽ���ϵͳ����ʱ����,�ɹ�ʱ������
	bool AddStudent(const std::string, const std::string, const bool, const unsigned int, const Problem*);
};

