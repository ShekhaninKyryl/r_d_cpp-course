#pragma once
#include "Coffee.h"

class Black : public Coffee
{
public:
	Black(Size size);

	void prepare();
};
