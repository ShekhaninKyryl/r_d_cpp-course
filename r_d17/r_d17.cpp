#include <iostream>
#include "Vector2d.h"

int main()
{
	Vector2d vector1;
	Vector2d vector2 = Vector2d(1.0, 2.0);


	/*
	* Output: {0.0; 0.0}
	* Output: {1.0; 2.0}
	*/
	std::cout << vector1 << '\n' << vector2 << '\n';
	std::cin >> vector1; // 3, 6

	/*
	* Output: {3.0; 6.0}
	* Output: {1.0; 2.0}
	*/
	std::cout << vector1 << '\n' << vector2 << '\n';

	Vector2d vector3 = vector1 + vector2;

	/*
	* Output: {4.0; 8.0}
	*/
	std::cout << vector3 << '\n';

	/*
	* 2.2 = (1 + 4)^1/2
	*/
	std::cout << vector2() << '\n';

	/*
	* x:1.0
	* y:2.0
	* undef:  <-- Exception Thrown...
	*/
	//std::cout << "x:" << vector2[0] <<"\ny:" << vector2[1] << "\nundef:" << vector2[2] << '\n';


	/*
	* Output: {2.0; 4.0}
	*/
	vector2 *= 2;
	std::cout << vector2 << '\n';

	/*
	* 3
	*/
	std::cout << "Counter: " << Vector2d::getCounter() << '\n';

	/*
	* 2
	*/
	vector1.~Vector2d();
	std::cout << "Counter: " << Vector2d::getCounter() << '\n';

}