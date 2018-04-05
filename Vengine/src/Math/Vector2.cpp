#include "Vengine/Vector2.h"
#include <glm/glm.hpp>


Vector2::Vector2(float x, float y) :
	x_(x),
	y_(y)
{}

Vector2::Vector2() :
	x_(0),
	y_(0)
{}

float Vector2::x() { return x_; }
float Vector2::y() { return y_; }

void Vector2::set_x(float x) { x_ = x; }
void Vector2::set_y(float y) { y_ = y; }

float Vector2::length()
{
	return glm::sqrt(glm::pow(x_, 2) + pow(y_, 2));
}

Vector2 Vector2::normalized()
{
	float length = this->length();
	return Vector2(x_ / length, y_ / length);
}

Vector2::~Vector2()
{
}
