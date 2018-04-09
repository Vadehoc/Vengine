#include <Vengine/GameObject.h>

namespace vengine {

	GameObject::GameObject()
		:name("GameObject")
	{

	}

	GameObject::GameObject(std::string nameP)
		:name(nameP)
	{

	}

	void GameObject::update()
	{
		for (int i = 0; i != this->components.size(); i++)
		{
			components[i]->update();
		}
	}

	void GameObject::start()
	{
		for (int i = 0; i != this->components.size(); i++)
		{
			components[i]->start();
		}
	}

	void GameObject::end()
	{
		for (int i = 0; i != this->components.size(); i++)
		{
			components[i]->end();
		}
	}

	void GameObject::render()
	{
		for (int i = 0; i != this->components.size(); i++)
		{
			components[i]->render();
		}
	}

}