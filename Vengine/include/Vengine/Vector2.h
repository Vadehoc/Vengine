#pragma once

#include <iostream>

class Vector2
{
public:
	Vector2(float x, float y);
	Vector2();
	~Vector2();

	friend std::ostream& operator<< (std::ostream& stream, const Vector2& vector)
	{
		stream << "(" << vector.x_ << ", " << vector.y_ << ")";
		return stream;
	}

	float x();
	float y();

	void set_x(float x);
	void set_y(float y);

	float length_sqr();
	float length();
	void normalize();
	Vector2 normalized();

private:
	float x_, y_;
};

