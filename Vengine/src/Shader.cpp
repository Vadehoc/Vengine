#include "Vengine\Shader.h"


Shader::Shader()
{
	this->vertexShader = glCreateShader(GL_VERTEX_SHADER);
	this->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, &this->vertexSource, NULL);
	glShaderSource(fragmentShader, 1, &this->fragmentSource, NULL);
}


Shader::~Shader()
{
	delete(vertexSource);
	delete(fragmentSource);
}
