#pragma once

#include "Commons.h"

class CMainWindow
{
public:
	CMainWindow(); 
	~CMainWindow();
	static void InitInstance();

private:
	GLFWwindow* _window;

	static CMainWindow* s_Instance;
};
