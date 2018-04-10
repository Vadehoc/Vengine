#pragma once
#define GLEW_STATIC
#include <GL\glew.h>
#include <vector>
class Mesh
{
public:
	Mesh();
	Mesh(std::vector<GLfloat> vertexData, std::vector<GLuint> indices);
	~Mesh();

	void draw();

	GLuint vbo;
	GLuint vao;
	GLuint ebo;
	std::vector<GLfloat> vertexData;
	std::vector<GLuint> indices;

};

