#include <iostream>

#include "Water.h"


Water::Water(Size size)
{
	cost = 0.0;
	this->size = size;
}

void Water::prepare()
{
	std::cout << "Type: Water\n";
	std::cout << "Cost: " << "Water is free" << "\n\n";
}
