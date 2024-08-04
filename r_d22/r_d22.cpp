#include <iostream>
#include "DynamicArray.h"

//1. Розширити клас DynamicIntArray, реалізований у Лекції 19:
//a.Зробити клас темплейтним для підтримки будь - якого внутрішнього типу, не лише
//int;
//b.Додати методи :
//i.Реалізація функціонала резервування пам’яті :
//void reserve(std::size_t reservedSpace);
//std::size_t getCapacity() const;
//void shrinkToFit();
//ii. void pop_back();
//Type back() const;
//bool operator==(const DynamicArray& other) const;


int main()
{
	///*FLOAT TEST*/
	//DynamicIntArray<float> array1;

	//array1.push_back(0.2);
	//array1.push_back(1.1);
	//array1.push_back(2.6);
	//array1.push_back(30.5);

	//std::cout << array1[3] << '\n';

	//DynamicIntArray<float> array2 = array1;

	//std::cout << array2[3] << '\n';

	//array1.clear();
	//// std::cout << array1[3] << '\n'; //Exception thrown: read access violation.

	//array1.setSize(5);
	//std::cout << array1[3] << '\n'; // heap deata

	//std::cout << array2[3] << '\n';



	///* CHAR TEST*/
	//DynamicIntArray<char> ch1;

	//ch1.push_back('q');
	//ch1.push_back('w');
	//ch1.push_back('e');
	//ch1.push_back('r');

	//std::cout << ch1[3] << '\n';

	//DynamicIntArray<char> ch2 = ch1;

	//std::cout << ch2[3] << '\n';

	//ch1.clear();
	//// std::cout << array1[3] << '\n'; //Exception thrown: read access violation.

	//ch1.setSize(5);
	//std::cout << ch1[3] << '\n'; // heap deata

	//std::cout << ch2[3] << '\n';


	DynamicIntArray<int> array1;
	array1.reserve(20);
	array1.push_back(1);
	array1.push_back(2);
	array1.push_back(3);
	array1.push_back(4);
	array1.push_back(5);


	DynamicIntArray<int> array2 = array1;

	array2.push_back(6);
	array2.pop_back();

	std::cout << (array1 == array2);
}
