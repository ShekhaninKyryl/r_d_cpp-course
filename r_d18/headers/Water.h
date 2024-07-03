#pragma once
#include "Drink.h"

class Water : public Drink
{
public:
	Water(Size size);

	void prepare();
	float getCost() { return cost; };
};
