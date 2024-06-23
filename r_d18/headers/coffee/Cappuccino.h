#pragma once
#include "Coffee.h"

class Cappuccino : public Coffee
{
public:
	Cappuccino(Size size);

	void prepare();
};
