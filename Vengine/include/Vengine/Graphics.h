#pragma once
#define GLEW_STATIC

#include <iostream>
#include <stdio.h>
#include <map>

#include <GL/glew.h>
#include <GL/GLU.h>
#include <GLFW\glfw3.h>

#include <SDL\SDL.h>

#include <Vengine\Scene.h>
#include <Vengine\Mesh.h>
#include <Vengine\Shader.h>
#include <Vengine\Vector3.h>

namespace vengine {

	class Graphics
	{
	public:

		Graphics();
		~Graphics();

		bool initialize(const char* window_name, int width, int height, Vector3 color);
		bool initialize(const char* window_name, int width, int height);
		bool isClosing();
		void swapBuffer();
		void setClearColor(float r, float g, float b);
		void setClearColor(Vector3 color);
		void clearScreen();
		void quit();
		void renderScene();
	private:

		int _width, _height;
		SDL_Window* window;
		SDL_Surface* surface;
		Scene* scene;

		std::map < std::string, Mesh> meshData;
		std::map < std::string, Shader> shaderData;

	};

}