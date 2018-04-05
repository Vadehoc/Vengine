#pragma once
#include <iostream>

namespace vengine {
	class Component
	{
	public:
		Component();
		virtual ~Component();
		virtual void update();
		virtual void start();
		virtual void end();

	};
}

