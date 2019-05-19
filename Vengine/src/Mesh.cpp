#include <Vengine\Mesh.h>
#include <vector>


Mesh::Mesh()
{

}

Mesh::Mesh(std::vector<GLfloat> vertexData, std::vector<GLuint> indices, Shader shader)
{
	this->meshShader = shader;

	this->vertexData = vertexData;
	this->indices = indices;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &this->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float), &this->vertexData[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0); //Position Attribute
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(3 * sizeof(float))); //Color Attribute
	glEnableVertexAttribArray(1);

	glGenBuffers(1, &this->ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &this->indices[0], GL_STATIC_DRAW);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void Mesh::draw()
{
	meshShader.use();
	glBindVertexArray(this->vao);
	GLuint lineLocation = glGetUniformLocation(meshShader.shaderProgram, "line");

	glUniform1i(lineLocation, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, 0);

	glUniform1i(lineLocation, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawElements(GL_LINE_STRIP, this->indices.size(), GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}


Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &this->vao);
	glDeleteBuffers(1, &this->vbo);
	glDeleteBuffers(1, &this->ebo);
}
