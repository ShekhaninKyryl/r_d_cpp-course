#include <iostream>
#include "Arabica.h"

Arabica::Arabica(Size size)
{
	this->size = Size::Small;
	switch (size)
	{
	case Size::Small:
		cost = 1;
		break;
	case Size::Medium:
		cost = 1.5;
		break;
	case Size::Large:
		cost = 2.0;
		break;
	case Size::XLarge:
		cost = 2.2;
		break;
	default:
		this->size = Size::Invalid;
	}

}

void Arabica::prepare()
{
	std::cout << "Type: Arabica\n";
	std::cout << "Cost: " << cost << "\n\n";
}
