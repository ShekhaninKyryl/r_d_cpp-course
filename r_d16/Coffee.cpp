#include <iostream>
#include "Coffee.h"

Coffee::Coffee()
{
	type = CoffeeType::Arabica;
	cost = 1.0;
}

Coffee::Coffee(CoffeeType type)
{
	this->type = type;
	cost = 0.0;
	switch (type)
	{
	case CoffeeType::Arabica:
		cost = 1.0;
		break;
	case CoffeeType::Robusta:
		cost = 1.5;
		break;
	case CoffeeType::Black:
		cost = 0.5;
		break;
	case CoffeeType::Latte:
		cost = 2;
		break;
	case CoffeeType::Cappuccino:
		cost = 0.75;
		break;
	case CoffeeType::Espresso:
		cost = 1.0;
		break;
	}
}

void Coffee::prepare()
{
	std::cout << "Coffee is prepearing...\n";
	switch (type)
	{
	case CoffeeType::Arabica:
		std::cout << "Type: Arabica\n";
		break;
	case CoffeeType::Robusta:
		std::cout << "Type: Robusta\n";
		break;
	case CoffeeType::Black:
		std::cout << "Type: Black\n";
		break;
	case CoffeeType::Latte:
		std::cout << "Type: Latte\n";
		break;
	case CoffeeType::Cappuccino:
		std::cout << "Type: Cappuccino\n";
		break;
	case CoffeeType::Espresso:
		std::cout << "Type: Espresso\n";
		break;
	}

	std::cout << "Cost: " << cost << "\n\n";
}
