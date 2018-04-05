#include <iostream>
#pragma once
namespace vengine {
	class Vector3
	{
	public:
		Vector3(float x, float y, float z);
		Vector3();
		~Vector3();

		friend std::ostream& operator<< (std::ostream& stream, const Vector3& vector) 
		{
			stream << "(" << vector.x_ << ", " << vector.y_ << ", " << vector.z_ << ")";
			return stream;
		}

		friend Vector3 operator+ (const Vector3 u, const Vector3 v)
		{
			return Vector3(u.x_ + v.x_, u.y_ + v.y_, u.z_ + v.z_);
		}

		friend Vector3 operator- (const Vector3 u, const Vector3 v)
		{
			return Vector3(u.x_ + v.x_, u.y_ + v.y_, u.z_ + v.z_);
		}

		
		//---------------------Accessors--------------------
		float x();
		float y();
		float z();

		void set_x(float x);
		void set_y(float y);
		void set_z(float z);

		//Directions
		const static Vector3 kZero;
		const static Vector3 kUp;
		const static Vector3 kDown;
		const static Vector3 kForward;
		const static Vector3 kBack;
		const static Vector3 kLeft;
		const static Vector3 kRight;

		float length_sqr();
		float length();
		void normalize();
		Vector3 normalized();

	private:

		float x_, y_, z_;

	};
}