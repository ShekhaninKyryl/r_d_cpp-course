#include <iostream>

#include "Reactangle.h"
#include "CoffeeShop.h"

int main()
{
	//Rectangle rect = Rectangle();
	//Rectangle rectWithParams = Rectangle(2.0, 3.0);


	//std::cout << "Default rectangle: "
	//	<< "\nArea - " << rect.getArea()
	//	<< "\nPerimeter - " << rect.getPerimeter() << std::endl;

	//std::cout << "Default rectangle: "
	//	<< "\nArea - " << rectWithParams.getArea()
	//	<< "\nPerimeter - " << rectWithParams.getPerimeter() << std::endl;

	// Throw exception
	// Rectangle rectWronParams = Rectangle(-2.0, 3.0);


	CoffeeShop* shop = new CoffeeShop("Barbarista", 2);

	std::cout << "3 Clients would like to make order.\n";
	for (int i = 0; i < 3; i++) {
		int place = shop->takePlace();
		if (place == -1) {
			std::cout << "Sorry no more free place...\n";
			break;
		}
		else {
			std::cout << "Table #" << place << " has been taken.\n";
		}

		shop->order(place);
		shop->prepare(place);
	}

	std::cout << "Table #1 want get receipt.\n";
	shop->getReceipt(1);


	std::cout << "1 Clients would like to make order.\n";
	for (int i = 0; i < 1; i++) {
		int place = shop->takePlace();
		if (place == -1) {
			std::cout << "Sorry no more free place...\n";
			break;
		}
		else {
			std::cout << "Table #" << place << " has been taken.\n";
		}

		shop->order(place);
		shop->prepare(place);
	}
}