#include "Vengine/Scene.h"
#include <algorithm>

namespace vengine
{

	Scene::Scene()
		:name("Scene")
	{
	}

	Scene::Scene(std::string name)
		:name(name)
	{
	}


	Scene::~Scene()
	{
	}

	void Scene::update()
	{
		for (unsigned int i = 0; i < this->gameObjects.size(); i++)
		{
			gameObjects[i].update();
		}
	}

	void Scene::start()
	{
		for (unsigned int i = 0; i < this->gameObjects.size(); i++)
		{
			gameObjects[i].start();
		}
	}

	void Scene::end()
	{
		for (unsigned int i = 0; i < this->gameObjects.size(); i++)
		{
			gameObjects[i].end();
		}
	}

	void Scene::render()
	{
		for (unsigned int i = 0; i < this->gameObjects.size(); i++)
		{
			gameObjects[i].render();
		}
	}

	GameObject* Scene::addGameObject()
	{
		GameObject go = GameObject();
		gameObjects.push_back(go);
		return &gameObjects.back();
	}

	GameObject* Scene::addGameObject(const std::string nameP)
	{
		gameObjects.push_back(GameObject(nameP));
		return &gameObjects.back();
	}

	GameObject* Scene::findGameObject(const std::string name)
	{
		for (int i = 0; i < gameObjects.size(); i++)
		{
			if (gameObjects[i].name == name)
				return &gameObjects[i];
		}
		return NULL;
	}
}