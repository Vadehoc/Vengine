#pragma once
#include <vector>
#include <memory>
#include <Vengine\System.h>

class SystemManager
{
public:
	SystemManager();
	~SystemManager();

	std::vector<std::shared_ptr<System>> systems;

	template <class T>
	T* addSystem()
	{
		static_assert(std::is_base_of<System, T>::value, "T must be a descendant of System");
		T* tempT = new T();
		systems.push_back(std::shared_ptr<T>(tempT));
		return tempT;
	};

	template <class T>
	T* GetSystem()
	{
		if (!systems.empty())
		{
			for (unsigned int i = 0; i < systems.size(); i++)
			{
				if (typeid(*(systems[i])) == typeid(T)) {
					std::shared_ptr<T> tempT = std::dynamic_pointer_cast<T, System>(systems[i]);
					return tempT.get();
				}
			}
		}
	};
};

