#pragma once

//#define VECTOR3_UNIT_TESTS

#include <cmath>

template<typename Ty>
struct vector3
{
	Ty x, y, z;

	//constexpr vector3() : x(0), y(0), z(0) {}

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

	inline constexpr vector3 operator * (const Ty& other) const
	{
		return { x * other,y * other,z * other };
	}

	inline constexpr vector3 operator / (const vector3& other) const
	{
		return { x / other.x,y / other.y,z / other.z };
	}

	inline constexpr vector3 operator / (const Ty& other) const
	{
		return { x / other,y / other,z / other };
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

	inline constexpr vector3& operator *= (const Ty& other)
	{
		x *= other;
		y *= other;
		z *= other;
		return *this;
	}

	inline constexpr vector3& operator /= (const vector3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}

	inline constexpr vector3& operator /= (const Ty& other)
	{
		x /= other;
		y /= other;
		z /= other;
		return *this;
	}

	constexpr double length() const
	{
		return sqrt(x * x + y * y + z * z);
	}

	constexpr vector3& normalize()
	{
		double len = length();
		x /= len;
		y /= len;
		z /= len;
		return *this;
	}

	constexpr vector3 normalized() const
	{
		double len = length();
		return { x / len, y / len,z / len };
	}

	inline constexpr bool operator == (const vector3& other) const
	{
		return x == other.x && y == other.y && z == other.z;
	}

	inline constexpr bool operator != (const vector3& other) const
	{
		return x != other.x || y != other.y || z != other.z;
	}

	constexpr bool equals (const vector3& other, double tolerance) const
	{
		return (*this - other).length() <= tolerance;
	}

	inline constexpr bool()
	{
		return x == 0 && y == 0 && z == 0;
	}
};

template<typename Ty>
inline constexpr double dot(const vector3<Ty>& a, const vector3<Ty>& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

#ifdef VECTOR3_UNIT_TESTS

#include <string>

template<typename Ty>
std::wstring ToString(const vector3<Ty>& q)
{
	std::wstring result = L"x=";
	result += std::to_wstring(q.x) + L", y=";
	result += std::to_wstring(q.y) + L", z=";
	result += std::to_wstring(q.z);
	return result;
}

#endif // VECTOR3_UNIT_TESTS