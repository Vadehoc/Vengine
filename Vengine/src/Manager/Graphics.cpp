#include <Vengine\Graphics.h>
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace vengine {

	Graphics::Graphics()
	{
	}


	Graphics::~Graphics()
	{
		delete window;
	}

	void window_close_callback(GLFWwindow* window)
	{
		if (true)
			glfwSetWindowShouldClose(window, GLFW_FALSE);
	}

	void onResize(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
		glm::mat4 proj = glm::perspective(glm::radians(90.0f), (float)width / height, 0.5f, 10.0f);
		glUniformMatrix4fv(2, 1, GL_FALSE, glm::value_ptr(proj));
	}

	bool Graphics::initialize(const char* window_name, int width, int height, Vector3 color)
	{
		glewExperimental = true;
		glewInit();

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		}else
		{
			//Create window
			window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
			if (window == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			}else
			{
				//Get window surface
				surface = SDL_GetWindowSurface(window);

				//Update the surface
				SDL_UpdateWindowSurface(window);
			}
		}

		glEnable(GL_DEPTH_TEST);

		setClearColor(color);
		return true;
	}

	bool Graphics::initialize(const char* window_name, int width, int height)
	{
		return this->initialize(window_name, width, height, Vector3(0, 0, 0));
	}

	bool Graphics::isClosing() {
		return glfwWindowShouldClose(window);
	}

	void Graphics::swapBuffer() {
		glfwSwapBuffers(window);
	}



	void Graphics::setClearColor(float r, float g, float b)
	{
		glClearColor(r, g, b, 1.0f);
	}
	
	void Graphics::setClearColor(Vector3 color)
	{
		std::cout << color.x() << color.y() << color.z();
		glClearColor(color.x(), color.y(), color.z(), 1.0f);
	}

	void Graphics::clearScreen()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	}

	void Graphics::renderScene()
	{
		this->scene->render();
	}

	void Graphics::quit()
	{
		glfwTerminate();
		
	}

}