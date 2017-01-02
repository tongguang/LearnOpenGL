#include "Tool.h" 

std::string ReadFileData(std::string filePath)
{
	std::ifstream fileString(filePath);
	std::string fileStr((std::istreambuf_iterator<char>(fileString)),
		std::istreambuf_iterator<char>());
	return fileStr;
}
