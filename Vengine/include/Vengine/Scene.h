#pragma once
#include <vector>
#include <string>
#include <Vengine/GameObject.h>

namespace vengine {
	class Scene
	{
	public:
		Scene();
		Scene(std::string name);
		~Scene();

		std::string name;

		void update();
		void start();
		void end();

		GameObject* addGameObject();
		GameObject* addGameObject(std::string name);

		GameObject* findGameObject(std::string name);

	private:
		std::vector<GameObject> gameObjects;
	};
}

