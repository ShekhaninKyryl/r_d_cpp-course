#include <iostream>
#include "Black.h"

Black::Black(Size size)
{
	this->size = Size::Small;
	switch (size)
	{
	case Size::Medium:
		cost = 1.0;
		break;
	case Size::Large:
		cost = 1.5;
		break;
	case Size::XLarge:
		cost = 2.0;
		break;
	default:
		this->size = Size::Invalid;
	}
}

void Black::prepare()
{
	std::cout << "Type: Black\n";
	std::cout << "Cost: " << cost << "\n\n";
}
