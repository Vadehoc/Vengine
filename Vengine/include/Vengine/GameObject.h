#pragma once
#include <string>
#include <typeinfo>
#include <iostream>
#include <memory>
#include <vector>
#include <Vengine/Component.h>

namespace vengine {

	class GameObject
	{
	public:

		GameObject();
		GameObject(std::string nameP);

		~GameObject();

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
			try {
				components.push_back(tempT);
			}
			catch (const std::exception& e)
			{
				printf(e.what());
			}
			return tempT;
		};

		template <class T>
		T* GetComponent()
		{
			if (!components.empty())
			{
				for (unsigned int i = 0; i < components.size(); i++)
				{
					if (typeid(*components[i]) == typeid(T)) {
						return static_cast<T*>(components[i]);
					}
				}
			}
		};


	private://------------------Private Members-----------------
		std::vector<Component*> components;
	};
}