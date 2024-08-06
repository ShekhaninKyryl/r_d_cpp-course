#include <stdexcept>
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

Vector2d::Vector2d(float x0, float y0, float x1, float y1)
{
	x = x1 - x0;
	y = y1 - y0;
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

const float Vector2d::operator()()
{
	return static_cast<float>(std::sqrt(x * x + y * y));
}

float Vector2d::magnitude() const 
{
	return std::sqrt(x * x + y * y);
}

float& Vector2d::operator[](std::size_t idx)
{
	if (idx == 0) return x;
	if (idx == 1) return y;
	throw std::out_of_range("Index out of range for Vector2d");
}

float Vector2d::dotProduct(Vector2d& other) const
{
	return x * other.x + y * other.y;
}

Vector2d Vector2d::negate() const
{
	return Vector2d(-x, -y);
}

/*
	Identical,
	coDirected,
	OppositeDirected,
	AcuteAngle,
	ObtuseAngle,
	RightAngle
*/

VectorRelativeState Vector2d::getRelativeState(Vector2d& other) const
{
	if (x == other.x && y == other.y) return VectorRelativeState::Identical;

	const float cos = this->dotProduct(other) / (magnitude() * other.magnitude());

	if (cos == 1.0f) return VectorRelativeState::coDirected;
	if (cos == -1.0f) return VectorRelativeState::OppositeDirected;
	if (cos > 0.0f && cos < 1.0f) return VectorRelativeState::AcuteAngle;
	if (cos > -1.0f && cos < 0.0f) return VectorRelativeState::ObtuseAngle;
	return VectorRelativeState::RightAngle;
}

void Vector2d::scale(float factorX, float factorY)
{
	x *= factorX;
	y *= factorY;
}

std::ostream& operator<<(std::ostream& out, Vector2d& vector)
{
	out << std::fixed  << "Output: {" << vector.x << "; " << vector.y << "}";
	return out;
}

std::istream& operator>>(std::istream& in, Vector2d& vector)
{
	in >> vector.x >> vector.y;
	return in;
}
