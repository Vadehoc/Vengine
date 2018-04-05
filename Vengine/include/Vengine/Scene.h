#pragma once
#include <vector>
#include <string>
#include <Vengine/GameObject.h>
#include <Vengine\SystemManager.h>

namespace vengine {
	class Scene
	{
	public:
		Scene();
		Scene(std::string name);
		~Scene();

		std::string name;
		SystemManager sysManager;

		void update();
		void start();
		void end();

		GameObject* addGameObject();
		GameObject* addGameObject(std::string name);

	private:
		std::vector<GameObject> gameObjects;
	};
}

