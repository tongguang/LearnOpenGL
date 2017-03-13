#include "Shader.h"
#include "Tool.h"

CShader::CShader(const std::string &vertexShaderPath, const std::string &fragmentShaderPath):
	_VertexShaderPath(vertexShaderPath), _FragmentShaderPath(fragmentShaderPath)
{
	auto vShader = CreateVertexShader();
	auto pShader = CreateFragmentShader();
	InitShaderProgram(vShader, pShader);
	glDeleteShader(vShader);
	glDeleteShader(pShader);
}

CShader::~CShader()
{
	glDeleteProgram(_ShaderProgram);
}

GLuint CShader::CreateVertexShader()
{
	auto vertexShader = glCreateShader(GL_VERTEX_SHADER);
	auto vShaderCode = ReadFileData(_VertexShaderPath).c_str();
	glShaderSource(vertexShader, 1, &vShaderCode, NULL);
	CompileShader(vertexShader);
	return vertexShader;
}

GLuint CShader::CreateFragmentShader()
{
	auto fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	auto fShaderCode = ReadFileData(_VertexShaderPath).c_str();
	glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
	CompileShader(fragmentShader);
	return fragmentShader;
}

bool CShader::CompileShader(GLuint shader)
{
	glCompileShader(shader);
	GLint isSuccess;
	GLchar infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &isSuccess);
	if (!isSuccess)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "CompileShader Error" << infoLog << std::endl;
		return false;
	}
	return true;
}

void CShader::InitShaderProgram(GLuint vShader, GLuint pShader)
{
	_ShaderProgram = glCreateProgram();
	glAttachShader(_ShaderProgram, vShader);
	glAttachShader(_ShaderProgram, pShader);
	glLinkProgram(_ShaderProgram);
	
	GLint isSuccess;
	GLchar infoLog[512];
	glGetProgramiv(_ShaderProgram, GL_LINK_STATUS, &isSuccess);
	if (!isSuccess) {
		glGetProgramInfoLog(_ShaderProgram, 512, NULL, infoLog);
		std::cout << "InitShaderProgram Error" << infoLog << std::endl;
	}
}

void CShader::Use()
{
	glUseProgram(_ShaderProgram);
}
