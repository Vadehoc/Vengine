#include <Vengine\Mesh.h>
#include <vector>


Mesh::Mesh()
{

}

Mesh::Mesh(std::vector<GLfloat> vertexData, std::vector<GLuint> indices)
{
	this->vertexData = vertexData;
	this->indices = indices;
}


Mesh::~Mesh()
{
}
