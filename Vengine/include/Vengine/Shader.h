#pragma once
#define GLEW_STATIC
#include <GL\glew.h>

#include <string>

class Shader
{
public:
	Shader();
	~Shader();

	char* vertexSource;
	char* fragmentSource;

	GLuint shaderProgram;

	GLuint vertexShader;
	GLuint fragmentShader;

};

