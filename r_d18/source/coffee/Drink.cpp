#include "Drink.h"
#include "Arabica.h"
#include "Black.h"
#include "Latte.h"
#include "Cappuccino.h"
#include "Espresso.h"

#include "Water.h"

Drink* Drink::createDrink(DrinkType drink, Size size)
{
	switch (drink)
	{
	case DrinkType::Arabica:
		return new Arabica(size);
	case DrinkType::Black:
		return new Black(size);
	case DrinkType::Latte:
		return new Latte(size);
	case DrinkType::Cappuccino:
		return new Cappuccino(size);
	case DrinkType::Espresso:
		return new Espresso();

	case DrinkType::Water:
		return new Water(size);
	}

	return nullptr;
}
