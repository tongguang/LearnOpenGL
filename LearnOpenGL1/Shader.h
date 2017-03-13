#pragma once
#include<string>

#include "Commons.h"

using namespace std;

class CShader
{
public:
	CShader(const std::string &vShaderPath, const std::string &pShaderPath);
	~CShader();
	GLuint CreateVertexShader();
	GLuint CreateFragmentShader();
	bool CompileShader(GLuint shader);
	void InitShaderProgram(GLuint vShader, GLuint pShader);
	void Use();
	GLuint& GetShaderProgram()
	{
		return _ShaderProgram;
	};

private:
	std::string _VertexShaderPath;
	std::string _FragmentShaderPath;
	GLuint _ShaderProgram;

};

