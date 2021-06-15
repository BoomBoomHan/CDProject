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
	System* sys = new System;
	sys->Test();
	delete sys;
	return 0;
	
	
}