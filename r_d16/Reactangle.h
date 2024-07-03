#pragma once


class Rectangle
{
public:
	Rectangle();
	Rectangle(float length, float height);

	float getArea();
	float getPerimeter();

	float getLength() { return length; }
	float getHeigth() { return height; }

private:
	float length;
	float height;
};