#include <Vengine\Mesh.h>
#include <vector>


Mesh::Mesh()
{

}

Mesh::Mesh(std::vector<GLfloat> vertexData, std::vector<GLuint> indices)
{
	this->vertexData = vertexData;
	this->indices = indices;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &this->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float), &this->vertexData[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); //Position Attribute
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &this->ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &this->indices[0], GL_STATIC_DRAW);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void Mesh::draw()
{
	glBindVertexArray(this->vao);
	glDrawElements(GL_TRIANGLES, this->vertexData.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}


Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &this->vao);
	glDeleteBuffers(1, &this->vbo);
	glDeleteBuffers(1, &this->ebo);
}
