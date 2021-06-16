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
	sys->AddProblem("010", "课程设计选题系统", "艾勇", "暂无", 30);
	cout << sys->OutputProb(OutputMethod::Complete) << endl;
	delete sys;
	return 0;
	
	
}