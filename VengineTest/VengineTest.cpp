#include "Vengine\Graphics.h"
#include <Vengine\Scene.h>
#include <Vengine\GameObject.h>
#include <Vengine\Transform.h>
#include <Windows.h>


int main(int argc, char *argv[], char *envp[]) {
	char* vertexShader = R"glsl(
		#version 150 core
		#extension GL_ARB_explicit_attrib_location : enable

		layout(location = 0)in vec3 position;

		void main()
		{
			gl_Position = vec4(position, 1.0);
		}
	)glsl";
	//proj * view * model * 
	char* fragmentShader = R"glsl(
		#version 150 core

		out vec4 outColor;

		void main()
		{
			outColor = vec4(1.0, 1.0, 1.0, 1.0);
		}
	)glsl";

	std::vector<float> vertecies = { 0.0f,  0.5f, 0.0f,// Vertex 1 (X, Y)
									 0.5f, -0.5f, 0.0f,// Vertex 2 (X, Y)
									-0.5f, -0.5f, 0.0f };// Vertex 3 (X, Y)}

	std::vector<GLuint> indices = { 0, 1, 2 };

	vengine::Graphics graph = vengine::Graphics();
	if (!graph.initialize("VengineTest", 600, 450, vengine::Vector3(0.172f, 0.242f, 0.313f)))
		exit(0);


	vengine::Scene scene = vengine::Scene();
	scene.addGameObject("testObject");

	Shader testShader = Shader(vertexShader, fragmentShader);
	testShader.use();

	Mesh mesh = Mesh(vertecies, indices);

	while (!graph.isClosing())
	{
		graph.clearScreen();
		scene.update();
		mesh.draw();
		graph.swapBuffer();
		glfwPollEvents();
	}

}