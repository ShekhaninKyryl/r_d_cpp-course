#include <stdexcept>

#include "Reactangle.h"


Rectangle::Rectangle()
{
	length = 0.0;
	height = 0.0;
}

Rectangle::Rectangle(float length, float height)
{
	if(length < 0 || height < 0) throw std::invalid_argument("received negative value");
	this->length = length;
	this->height = height;
}

float Rectangle::getArea()
{
	return height * length;
}

float Rectangle::getPerimeter()
{
	return (height + length) * 2;
}
