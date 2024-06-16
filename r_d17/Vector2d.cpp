#include "Vector2d.h"

unsigned Vector2d::counter = 0;

Vector2d::Vector2d()
{
	this->x = 0.0;
	this->y = 0.0;

	counter++;
}

Vector2d::Vector2d(float x, float y)
{
	this->x = x;
	this->y = y;

	counter++;
}

Vector2d::~Vector2d()
{
	counter--;
}

Vector2d Vector2d::operator=(const Vector2d& vector)
{
	if (this != &vector) {
		x = vector.x;
		y = vector.y;
	}
	return *this;
}

Vector2d Vector2d::operator+(const Vector2d& secondVector)
{
	return Vector2d(x + secondVector.x, y + secondVector.y);
}

Vector2d Vector2d::operator-(const Vector2d& secondVector)
{
	return Vector2d(x - secondVector.x, y - secondVector.y);
}

Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector)
{
	return Vector2d(leftVector.x + rightVector.x, leftVector.y + rightVector.y);
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector)
{
	return Vector2d(leftVector.x - rightVector.x, leftVector.y - rightVector.y);
}

void Vector2d::operator*=(float scalar)
{
	x *= scalar;
	y *= scalar;
}

float Vector2d::operator()()
{
	return static_cast<float>(std::sqrt(x * x + y * y));
}

float& Vector2d::operator[](std::size_t idx)
{
	if (idx == 0) return x;
	if (idx == 1) return y;
}

std::ostream& operator<<(std::ostream& out, Vector2d& vector)
{
	out << std::fixed << std::setprecision(1) << "Output: {" << vector.x << "; " << vector.y << "}";
	return out;
}

std::istream& operator>>(std::istream& in, Vector2d& vector)
{
	in >> vector.x >> vector.y;
	return in;
}
