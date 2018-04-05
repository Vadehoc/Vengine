#pragma once
#include <Vengine/Component.h>
#include <Vengine/Vector3.h>
namespace vengine {
	class Transform : public Component
	{
	public:
		Vector3 position_, scale_;

		Transform();
		~Transform();
	};
}