#pragma once
#include "Coffee.h"

class Latte : public Coffee
{
public:
	Latte(Size size);

	void prepare();
};
