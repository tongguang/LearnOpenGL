#include "MainWindow.h"

void DestroyInstance()
{
	CMainWindow::DestroyInstance();
}

int main()
{
	
	auto mainWindow = CMainWindow::GetInstance();
	auto window = mainWindow->GetWindow();
	while (!glfwWindowShouldClose(window))
	{
		mainWindow->Update();
	}
	DestroyInstance();
	return 0;
}