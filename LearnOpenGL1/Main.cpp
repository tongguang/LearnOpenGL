#include "MainWindow.h"

void DestroyInstance()
{
	CMainWindow::DestroyInstance();
}

int main()
{
	
	auto mainWindow = CMainWindow::GetInstance();
	mainWindow->Run();
	DestroyInstance();
	return 0;
}