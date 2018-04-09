#pragma once
#include <string>
#include <memory>
#include <vector>
#include <Vengine/Component.h>

namespace vengine {

	class GameObject
	{
	public:

		GameObject();
		GameObject(std::string nameP);

		std::string name;
		//-------------------Frame-Events-------------------
		
		void update();
		void start();
		void end();
		void render();

		//----------------Component-functions---------------

		template <class T>
		T* addComponent()
		{
			static_assert(std::is_base_of<Component, T>::value, "T must be a descendant of Component");
			T* tempT = new T();
			components.push_back(std::shared_ptr<T>(tempT));
			return tempT;
		};

		template <class T>
		T* GetComponent()
		{
			if (!components.empty())
			{
				for (unsigned int i = 0; i < components.size(); i++)
				{
					if (typeid(*(components[i])) == typeid(T)) {
						std::shared_ptr<T> tempT = std::dynamic_pointer_cast<T, Component>(components[i]);
						return tempT.get();
					}
				}
			}
		};


	private://------------------Private Members-----------------
		std::vector<std::shared_ptr<Component>> components;
	};
}