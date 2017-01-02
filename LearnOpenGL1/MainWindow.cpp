#include "MainWindow.h"

CMainWindow* CMainWindow::s_Instance = nullptr;

CMainWindow::CMainWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	int w, h;
	w = 800;
	h = 600;
	this->_window = glfwCreateWindow(w, h, "LearnOpenGL", nullptr, nullptr);

	glfwMakeContextCurrent(this->_window);
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
	}

	int width, height;
	glfwGetFramebufferSize(this->_window, &width, &height);
	glViewport(0, 0, width, height);
}

CMainWindow::~CMainWindow()
{
	glfwTerminate();
}

CMainWindow* CMainWindow::GetInstance()
{
	if (!s_Instance)
	{
		s_Instance = new CMainWindow();
	}
	return s_Instance;
}

void CMainWindow::DestroyInstance()
{
	if (s_Instance)
	{
		delete s_Instance;
		s_Instance = nullptr;
	}
}

void CMainWindow::Run()
{
	while (!glfwWindowShouldClose(this->_window))
	{
		this->Update();
	}
}

void CMainWindow::Update()
{
	glfwPollEvents();
	glfwSwapBuffers(this->_window);
}
