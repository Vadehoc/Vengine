#include "Vengine\Graphics.h"
#include <Vengine\Scene.h>
#include <Vengine\GameObject.h>
#include <Vengine\Transform.h>


int WinMain() {
	vengine::Graphics graph = vengine::Graphics();
	graph.initialize("test", 600, 450);
	vengine::Scene scene = vengine::Scene();
	scene.addGameObject("testObject");
	vengine::GameObject* go = scene.findGameObject("testObject");
	go->addComponent<vengine::Transform>();
	while (!graph.isClosing())
	{
		graph.clearScreen(0.4f, 0.3f, 0.75f);
		scene.update();
		graph.swapBuffer();
		glfwPollEvents();
	}

}