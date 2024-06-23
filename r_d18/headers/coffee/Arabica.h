#pragma once
#include "Coffee.h"

class Arabica : public Coffee
{
public:
	Arabica(Size size);

	void prepare();
};
