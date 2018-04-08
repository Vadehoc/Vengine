#pragma once
#define GLEW_STATIC

#include <iostream>
#include <map>

#include <GL/glew.h>
#include <GL/GLU.h>
#include <GLFW\glfw3.h>

#include <Vengine\Scene.h>

namespace vengine {

	class Graphics
	{
	public:

		Graphics();
		~Graphics();

		bool initialize(const char* window_name, int width, int height);
		bool isClosing();
		void swapBuffer();
		void clearScreen(float r, float g, float b);
		void swap_window();
		void quit();
		void renderScene();
	private:

		int _width, _height;
		GLFWwindow* window;
		Scene* scene;

		std::map < std::string, GLuint> vao;

	};

}