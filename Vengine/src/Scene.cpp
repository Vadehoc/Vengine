#include "Vengine/Scene.h"

namespace vengine
{

	Scene::Scene()
		:name("Scene"),
		 sysManager(SystemManager())
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

	GameObject* Scene::addGameObject()
	{
		GameObject go = GameObject();
		gameObjects.push_back(GameObject());
		return &gameObjects.back();
	}

	GameObject* Scene::addGameObject(const std::string nameP)
	{
		gameObjects.push_back(GameObject(nameP));
		return &gameObjects.back();
	}
}