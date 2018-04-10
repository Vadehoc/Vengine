#include "Vengine/Vector3.h"
#include <glm/glm.hpp>

namespace vengine {

	const Vector3 Vector3::kZero = Vector3::Vector3(0, 0, 0);
	const Vector3 Vector3::kUp = Vector3::Vector3(0, 0, 1.0f);
	const Vector3 Vector3::kDown = Vector3::Vector3(0, 0, -1.0f);
	const Vector3 Vector3::kForward = Vector3::Vector3(0, 1.0f, 0);
	const Vector3 Vector3::kBack = Vector3::Vector3(0, -1.0f, 0);
	const Vector3 Vector3::kLeft = Vector3::Vector3(-1.0f, 0, 0);
	const Vector3 Vector3::kRight = Vector3::Vector3(1.0f, 0, 0);

	Vector3::Vector3(float x, float y, float z) :
		x_(x),
		y_(y),
		z_(z)
	{}

	Vector3::Vector3():
		x_(0),
		y_(0),
		z_(0)
	{}

	float Vector3::x() { return x_; }
	float Vector3::y() { return y_; }
	float Vector3::z() { return z_; }

	void Vector3::set_x(float x) { x_ = x; }
	void Vector3::set_y(float y) { y_ = y; }
	void Vector3::set_z(float z) { z_ = z; }

	float Vector3::length_sqr()
	{
		return (x_ * x_) + (y_ * y_) + (z_ * z_);
	}

	float Vector3::length()
	{
		return glm::sqrt(length_sqr());
	}

	Vector3 Vector3::normalized()
	{
		float length = this->length();
		return Vector3(x_ / length, y_ / length, z_ / length);
	}

	Vector3::~Vector3()
	{
	}
}