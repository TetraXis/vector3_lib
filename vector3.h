#pragma once

#include <cmath>

template<typename Ty>
struct vector3
{
	Ty x, y, z;

	constexpr vector3(Ty new_x = 0, Ty new_y = 0, Ty new_z = 0) : x(new_x), y(new_y), z(new_z) {}

	constexpr vector3(const vector3&) = default;

	inline constexpr vector3 operator + (const vector3& other) const
	{
		return { x + other.x,y + other.y,z + other.z };
	}

	inline constexpr vector3 operator - (const vector3& other) const
	{
		return { x - other.x,y - other.y,z - other.z };
	}

	inline constexpr vector3 operator * (const vector3& other) const
	{
		return { x * other.x,y * other.y,z * other.z };
	}

	inline constexpr vector3 operator / (const vector3& other) const
	{
		return { x / other.x,y / other.y,z / other.z };
	}
	
	inline constexpr vector3& operator += (const vector3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	inline constexpr vector3& operator -= (const vector3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	inline constexpr vector3& operator *= (const vector3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	inline constexpr vector3& operator /= (const vector3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}

	inline constexpr double length()
	{
		return sqrt(x * x + y * y + z * z);
	}

	inline constexpr void normalize()
	{
		x /= length();
		y /= length();
		z /= length();
	}
};