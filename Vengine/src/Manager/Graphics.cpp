#include <Vengine\Graphics.h>

namespace vengine {

	Graphics::Graphics()
	{
	}


	Graphics::~Graphics()
	{
	}

	void window_close_callback(GLFWwindow* window)
	{
		if (true)
			glfwSetWindowShouldClose(window, GLFW_FALSE);
	}

	void onResize(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	bool Graphics::initialize(const char* window_name, int width, int height, Vector3 color)
	{
		glfwInit();
		glfwWindowHint(GLFW_REFRESH_RATE, 60);
		glfwWindowHint(GLFW_SAMPLES, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		window = glfwCreateWindow(width, height, window_name, NULL, NULL);

		glfwMakeContextCurrent(window);

		glewExperimental = GL_TRUE;
		GLenum err = glewInit();
		if (err != GLEW_OK)
		{
			printf("Error initializing GLEW! %s\n", glewGetErrorString(err));
			return false;
		}
		glEnable(GL_MULTISAMPLE);
		glEnable(GL_DEPTH_TEST);
		glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
		glEnable(GL_POLYGON_SMOOTH);
		glEnable(GL_BLEND);

		setClearColor(color);

		glfwSetWindowSizeCallback(window, onResize);
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