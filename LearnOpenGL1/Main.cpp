#include "MainWindow.h"
#include "Tool.h"
#include <iostream>

void DestroyInstance()
{
	CMainWindow::DestroyInstance();
}

int main()
{
	std::cout << ReadFileData("D:\\Learn\\LearnOpenGL\\LearnOpenGL1\\ceshi.txt") << endl;
	auto mainWindow = CMainWindow::GetInstance();
	mainWindow->Run();
	DestroyInstance();
	return 0;
}