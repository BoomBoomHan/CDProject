#include "FunctionLibrary.h"
#include <io.h>
#include <direct.h>

//template<typename T>
//std::string FunctionLibrary::ToString(T t)
//{
//	std::stringstream stream;
//	std::string result;
//	stream << T;
//	stream >> result;
//	stream.clear();
//	return result;
//}

std::string FunctionLibrary::CreateFolder(const std::string folderPath)
{
	const char* cPath = folderPath.c_str();
	if (_access(cPath, 0))
	{
		_mkdir(cPath);
	}
	return folderPath;
}

bool FunctionLibrary::OpenFile(std::ofstream& file, const std::string filePath, const bool isIosApp)
{
	std::ios::_Openmode openMode = isIosApp ? std::ios::app : std::ios::out;
	CloseFile(file);
	file.open(filePath, openMode);
	return !file.fail();
}

bool FunctionLibrary::OpenFile(std::ifstream& file, const std::string filePath)
{
	CloseFile(file);
	file.open(filePath);
	return !file.fail();
}

void FunctionLibrary::CloseFile(std::ifstream& file)
{
	if (file.is_open())
	{
		file.close();
	}
}

void FunctionLibrary::CloseFile(std::ofstream& file)
{
	if (file.is_open())
	{
		file.close();
	}
}