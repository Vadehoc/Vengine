#pragma once
#define GLEW_STATIC
#include <GL\glew.h>

class Shader
{
public:
	Shader();
	~Shader();

	char* vertexSource;


	GLuint shaderProgram;
	GLuint vertexShader;

};

