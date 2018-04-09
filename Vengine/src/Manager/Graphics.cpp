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

	bool Graphics::initialize(const char* window_name, int width, int height)
	{
		if (!glfwInit())
		{
			return false;
		}
		glewExperimental = GL_TRUE;
		glewInit();
		glfwWindowHint(GLFW_REFRESH_RATE, 60);
		window = glfwCreateWindow(width, height, window_name, NULL, NULL);
		glfwMakeContextCurrent(window);
		return true;
	}

	bool Graphics::isClosing() {
		return glfwWindowShouldClose(window);
	}

	void Graphics::swapBuffer() {
		glfwSwapBuffers(window);
	}

	void Graphics::clearScreen(float r, float g, float b)
	{

		glClearColor(r, g, b, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

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