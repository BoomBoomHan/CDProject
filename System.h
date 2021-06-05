#pragma once
#include "BBHList.h"
#include "Student.h"
#include "Problem.h"

class System//课程设计选题系统
{
private:

private:
	BBHList<Student> studentList;
	BBHList<Problem> problemList;

public:
	System();
};

