#pragma once


enum class CoffeeType
{
	Arabica,
	Robusta,
	Black,
	Latte,
	Cappuccino,
	Espresso,
	Unknown
};

class Coffee
{
public:
	Coffee();
	Coffee(CoffeeType type);

	void prepare();

	float getCost() { return cost; }

private:
	CoffeeType type;
	float cost;
};