#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

#ifdef _DEBUG
#define new DBG_NEW
#endif

#include "Vengine\Graphics.h"
#include <Vengine\Scene.h>
#include <Vengine\GameObject.h>
#include <Vengine\Transform.h>
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <chrono>
#include <Windows.h>


int main(int argc, char *argv[], char *envp[]) {
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	char* vertexShader = R"glsl(
		#version 150 core
		#extension GL_ARB_explicit_attrib_location : enable
		#extension GL_ARB_explicit_uniform_location : enable

		layout(location = 0)in vec3 position;
		layout(location = 1)in vec3 color;

		uniform mat4 model;
		uniform mat4 view;
		uniform mat4 proj;

		out vec3 Color;

		void main()
		{
			gl_Position = proj * view * model * vec4(position, 1.0);
			Color = color;
		}
	)glsl";
	//proj * view * model * 
	char* fragmentShader = R"glsl(
		#version 150 core

		in vec3 Color;
		out vec4 outColor;

		uniform bool line;

		void main()
		{
			if(line)
			{
				outColor = vec4(0.0, 0.0, 0.0, 1.0);
			}else{
				outColor = vec4(Color, 1.0);
			}
		}
	)glsl";

	std::vector<float> vertecies = {-0.5f,  0.5f, 0.5f, 1.0f, 0.0f, 0.0f,	// X , Y, Z, R, G, B	rot
									-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f,	//Blau
									 0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f,	//Grün
									 0.5f,  0.5f, 0.5f, 1.0f, 1.0f, 1.0f,	//Weiß
									-0.5f,  -0.5f, 0.5f, 0.0f, 1.0f, 0.0f,	//Grün
									-0.5f,  -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,	//Weiß
									 0.5f,  -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,	//Rot
									 0.5f,  -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, };	//Blau

	std::vector<GLuint> indices = { 0, 1, 2,
									2, 3, 0,
									4, 5, 6,
									6, 7, 4,
									4, 0, 3,
									3, 7, 4,
									4, 0, 1,
									1, 5, 4,
									5, 1, 2,
									2, 6, 5,
									7, 3, 2,
									2, 6, 7
	};

	vengine::Graphics graph = vengine::Graphics();
	if (!graph.initialize("VengineTest", 1200, 900, vengine::Vector3(0.172f, 0.242f, 0.313f)))
		exit(0);


	vengine::Scene scene = vengine::Scene();
	scene.addGameObject("testObject");

	Shader testShader = Shader(vertexShader, fragmentShader);
	testShader.use();
	Mesh mesh = Mesh(vertecies, indices, testShader);

	glm::mat4 model = glm::mat4();
	glm::mat4 view = glm::lookAt(
		glm::vec3(1.2f, 1.2f, 1.2f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	);
	glm::mat4 proj = glm::perspective(glm::radians(90.0f), 1200.0f / 900.0f, 0.5f, 10.0f);

	GLuint modelPos = glGetUniformLocation(mesh.meshShader.shaderProgram, "model");
	GLuint viewPos = glGetUniformLocation(mesh.meshShader.shaderProgram, "view");
	GLuint projPos = glGetUniformLocation(mesh.meshShader.shaderProgram, "proj");

	glUniformMatrix4fv(modelPos, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewPos, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projPos, 1, GL_FALSE, glm::value_ptr(proj));

	glLineWidth(3);

	auto t_start = std::chrono::high_resolution_clock::now();
	auto t_last = t_start;
	GLuint64 frame = 0;
	while (!graph.isClosing())
	{
		frame++;
		auto t_now = std::chrono::high_resolution_clock::now();
		float time = std::chrono::duration_cast<std::chrono::duration<float>>(t_now - t_start).count();
		glm::mat4 trans;
		trans = glm::rotate(
			trans,
			time * glm::radians(30.0f),
			glm::vec3(0.0f, 1.0f, 0.0f)
		);
		glUniformMatrix4fv(modelPos	, 1, GL_FALSE, glm::value_ptr(trans));

		graph.clearScreen();
		scene.update();
		mesh.draw();
		graph.swapBuffer();
		glfwPollEvents();
		t_now = std::chrono::high_resolution_clock::now();
		float t_delta = std::chrono::duration_cast<std::chrono::duration<float>>(t_now - t_last).count();
		t_last = t_now;
	
	}
	mesh.end();
}