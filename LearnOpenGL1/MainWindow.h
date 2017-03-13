#pragma once

#include "Commons.h"

class CMainWindow
{
public:
	CMainWindow(); 
	~CMainWindow();
	static CMainWindow* GetInstance();
	static void DestroyInstance();
	void Run();
	void Update();


private:
	GLFWwindow* _Window;

	static CMainWindow* s_Instance;
};
