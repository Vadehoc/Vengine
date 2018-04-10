#pragma once
#define GLEW_STATIC
#include <GL\glew.h>

#include <string>
#include <iostream>

class Shader
{
public:
	Shader(char* vertexShader, char* fragmentShader);
	~Shader();

	void use();

	char* vertexSource;
	char* fragmentSource;

	GLuint shaderProgram;

	GLuint vertexShader;
	GLuint fragmentShader;

};

