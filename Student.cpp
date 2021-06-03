#include "Student.h"

Student::Student(const std::string _stuID, const std::string _name, const bool _sex, const unsigned int _age, const Problem* _prob)
	:stuID(_stuID),
	name(_name),
	sex(_sex),
	age(_age),
	selectedProblem(const_cast<Problem*>(_prob))
{

}

Student::~Student()
{

}