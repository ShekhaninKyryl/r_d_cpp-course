#pragma once
#include <cstddef>
#include <iostream>
#include <iomanip>

enum class VectorRelativeState {
	Identical,
	coDirected,
	OppositeDirected,
	AcuteAngle,
	ObtuseAngle,
	RightAngle
};


class Vector2d
{
public:
	Vector2d();
	Vector2d(float x, float y);
	Vector2d(float x0, float y0, float x1, float y1);

	~Vector2d();


	Vector2d operator=(const Vector2d& vector);
	Vector2d operator+(const Vector2d& secondVector);
	Vector2d operator-(const Vector2d& secondVector);

	friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);
	friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector);

	friend std::ostream& operator<<(std::ostream& out, Vector2d& vector);
	friend std::istream& operator>>(std::istream& in, Vector2d& vector);

	void operator*=(float scalar);
	const float operator()();
	float& operator[](std::size_t idx);

	float magnitude() const;
	float dotProduct(Vector2d& other) const;
	Vector2d negate() const;
	VectorRelativeState getRelativeState(Vector2d& other) const;
	void scale(float factorX, float factorY);



	static unsigned getCounter() { return counter; }
private:
	static unsigned counter;

	float x;
	float y;
};