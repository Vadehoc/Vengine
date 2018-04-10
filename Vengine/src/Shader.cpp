#include "Vengine\Shader.h"


Shader::Shader(char* vertexShader, char* fragmentShader)
{
	this->vertexSource = vertexShader;
	this->fragmentSource = fragmentShader;

	this->vertexShader = glCreateShader(GL_VERTEX_SHADER);
	this->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	this->shaderProgram = glCreateProgram();

	glShaderSource(this->vertexShader, 1, &this->vertexSource, NULL);
	glShaderSource(this->fragmentShader, 1, &this->fragmentSource, NULL);

	glCompileShader(this->vertexShader);
	GLint vertexStatus;
	glGetShaderiv(this->vertexShader, GL_COMPILE_STATUS, &vertexStatus);
	if (vertexStatus == GL_TRUE)
		std::cout << "Vertex Shader compiled successfully" << std::endl;
	else
	{
		char buffer[512];
		glGetShaderInfoLog(this->vertexShader, 512, NULL, buffer);
		std::cout << "Vertex Shader NOT compiled successfully" << std::endl << buffer;
	}
	glCompileShader(this->fragmentShader);
	GLint fragmentStatus;
	glGetShaderiv(this->fragmentShader, GL_COMPILE_STATUS, &fragmentStatus);
	if (fragmentStatus == GL_TRUE)
		std::cout << "Fragment Shader compiled successfully" << std::endl;
	else
	{
		char buffer[512];
		glGetShaderInfoLog(this->fragmentShader, 512, NULL, buffer);
		std::cout << "Fragment Shader NOT compiled successfully" << std::endl << buffer;
	}

	glAttachShader(this->shaderProgram, this->vertexShader);
	glAttachShader(this->shaderProgram, this->fragmentShader);

	glLinkProgram(this->shaderProgram);
}

void Shader::use()
{
	glUseProgram(this->shaderProgram);
}

Shader::~Shader()
{
}
