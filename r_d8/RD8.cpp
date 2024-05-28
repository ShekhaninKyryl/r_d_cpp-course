#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include "RD8.h"




void countNumbers(int count)
{
	int positiveCount = 0;
	int zeroCount = 0;
	int negativeCount = 0;

	std::cout << "Enter " << count << " numbers and I'll show statistic!" << std::endl;

	int input;
	for (int i = 0; i < count; i++)
	{
		std::cin >> input;

		if (input > 0) positiveCount++;
		else if (input < 0) negativeCount++;
		else zeroCount++;
	}

	std::cout << "Positive - " << positiveCount << std::endl;
	std::cout << "Zero - " << zeroCount << std::endl;
	std::cout << "Negative - " << negativeCount << std::endl;
}

int factorial(int n)
{
	if (n <= 1)
		return n;
	return factorial(n - 1) * n;
}

int factorialLoop(int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

void factorialProgression()
{
	int numberOfLastElement = 0;
	do {
		std::cout << "Enter number of last element: ";
		std::cin >> numberOfLastElement;
	} while (!numberOfLastElement);

	std::cout << "Factorial value is: " << factorial(numberOfLastElement) << std::endl;
	std::cout << "FactorialLoop value is: " << factorialLoop(numberOfLastElement) << std::endl;
}

void printNaturalNumbers(int count, Variant variant, bool recursively)
{
	if (recursively) {
		switch (variant)
		{
		case Ascending: {
			std::cout << "Natural namber (ASC, REC): ";
			printAscRec(count-1);
			std::cout << std::endl;
			break;
		}
		case Descending: {
			std::cout << "Natural namber (DESC, REC): ";
			printDescRec(count-1);
			std::cout << std::endl;
			break;
		}
		default:
			break;
		}
	}
	else {
		switch (variant)
		{
		case Ascending: {
			std::cout << "Natural namber (ASC, LOOP): ";
			printAscLoop(count);
			std::cout << std::endl;
			break;
		}
		case Descending: {
			std::cout << "Natural namber (DESC, LOOP): ";
			printDescLoop(count);
			std::cout << std::endl;
			break;
		}
		default:
			break;
		}
	}
	return;
}

void printAscLoop(int count)
{
	for (int i = 0; i < count; i++) {
		std::cout << i << ", ";
	}
	return;
}

void printDescLoop(int count)
{
	for (int i = count - 1; i >= 0; i--) {
		std::cout << i << ", ";
	}
	return;
}

void printAscRec(int count)
{
	if (count < 0) return;
	printAscRec(count - 1);
	std::cout << count << ", ";
	return;
}

void printDescRec(int count)
{
	if (count < 0) return;
	std::cout << count << ", ";
	printDescRec(count - 1);
	return;
}

float getArea(float radius)
{
	float area = M_PI * pow(radius, 2);
	std::cout << "Area of circle: " << area << std::endl;
	return area;
}

float getCircumference(float radius)
{
	float circumference = M_PI * radius * 2;
	std::cout << "Circumference: " << circumference << std::endl;
	return circumference;
}


