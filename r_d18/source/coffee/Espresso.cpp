#include <iostream>
#include "Espresso.h"


Espresso::Espresso()
{
	size = Size::Small;
	cost = 1.5;
}

void Espresso::prepare()
{
	std::cout << "Type: Espresso\n";
	std::cout << "Cost: " << cost << "\n\n";
}
