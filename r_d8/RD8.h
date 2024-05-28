#pragma once


void countNumbers(int count);

int factorial(int n);
int factorialLoop(int n);
void factorialProgression();

enum Variant
{
	Ascending,
	Descending,
};
void printNaturalNumbers(int count, Variant variant = Variant::Ascending, bool recursively = false);
void printAscLoop(int count);
void printDescLoop(int count);
void printAscRec(int count);
void printDescRec(int count);

float getArea(float radius);
float getCircumference(float radius);
