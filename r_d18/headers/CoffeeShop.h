#pragma once



#include <iostream>
#include "Drink.h"

class CoffeeShop
{
public:
	CoffeeShop(std::string title, unsigned int tablesCount);
	~CoffeeShop();

	int takePlace();
	void order(int tableNumber);
	bool prepare(int tableNumber);
	bool getReceipt(int tableNumber);


private:
	std::string title;
	unsigned int tablesCount;

	bool* m_Tables;
	Drink** m_Orders;
};