#pragma once
#define GLEW_STATIC

//STD

#include <vector>

//OpenGl
#include <GL\glew.h>

//Internal
#include <Vengine/Shader.h>

class Mesh
{
public:
	Mesh();
	Mesh(std::vector<GLfloat> vertexData, std::vector<GLuint> indices, Shader shader);
	~Mesh();

	void draw();

	//Buffer Objects
	GLuint vao; //Vertex Array Object
	GLuint vbo;	//Vertex Buffer Object
	GLuint ebo; //Element Buffer Object

	//Vertex Sources
	std::vector<GLfloat> vertexData;
	std::vector<GLuint> indices;
	//Shaders
	Shader meshShader;

};

