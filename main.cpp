#include <list>
#include <iostream>
#include "Student.h"
#include "Problem.h"
#include "System.h"
#include <fstream>
#include <Windows.h>
#include <direct.h>
#include <io.h>
using namespace std;

int main()
{
	System* sys = new System("123", "123");
	sys->AddProblem("010", "�γ����ѡ��ϵͳ", "����", "����", 30);
	cout << sys->OutputProb(OutputMethod::Complete) << endl;
	delete sys;
	return 0;
	
	
}