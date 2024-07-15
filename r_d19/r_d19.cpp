#include <iostream>
#include "DynamicIntArray.h"

int main()
{
	DynamicIntArray array1;

	array1.push_back(0);
	array1.push_back(1);
	array1.push_back(2);
	array1.push_back(30);

	std::cout << array1[3] << '\n'; //30

	DynamicIntArray array2 = array1;

	std::cout << array2[3] << '\n'; //30

	array1.clear();
	// std::cout << array1[3] << '\n'; //Exception thrown: read access violation.

	array1.setSize(5);
	std::cout << array1[3] << '\n'; // heap deata

	std::cout << array2[3] << '\n'; // 30
}