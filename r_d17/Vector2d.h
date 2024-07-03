#pragma once
#include <cstddef>
#include <iostream>
#include <iomanip>


class Vector2d
{
public:
	Vector2d();
	Vector2d(float x, float y);

	~Vector2d();


	Vector2d operator=(const Vector2d& vector);
	Vector2d operator+(const Vector2d& secondVector);
	Vector2d operator-(const Vector2d& secondVector);

	friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);
	friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector);

	void operator*=(float scalar);
	float operator()();
	float& operator[](std::size_t idx);

	friend std::ostream& operator<<(std::ostream& out, Vector2d& vector);
	friend std::istream& operator>>(std::istream& in, Vector2d& vector);

	static unsigned getCounter() { return counter; }
private:
	static unsigned counter;

	float x;
	float y;
};