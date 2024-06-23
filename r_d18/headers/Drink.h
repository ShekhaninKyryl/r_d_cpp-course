#pragma once

enum class DrinkType
{
	Arabica,
	Black,
	Latte,
	Cappuccino,
	Espresso,

	Water,

	Unknown
};

enum class Size
{
	Small,
	Medium,
	Large,
	XLarge,
	Invalid,
};

class Drink
{
public:

	static Drink* createDrink(DrinkType drink, Size size);

	virtual void prepare() = 0;
	float getCost() { return cost; };

	Size size;
	float cost;
};