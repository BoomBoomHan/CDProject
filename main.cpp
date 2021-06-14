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
	/*System* sys = new System;
	sys->Test();
	delete sys;*/
	ofstream fout;
	//
	string filePath = "test";
	if (!_access(filePath.c_str(), 0))
	{
		cout << _mkdir(filePath.c_str());
	}
	fout.open(filePath + "out.txt");
	if (fout.fail())
	{
		cout << "´ò¿ªÊ§°Ü!" << endl;
	}
}