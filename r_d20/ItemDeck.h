#pragma once
#include <vector>
#include "Deck.h"

class Item;

class ItemDeck:Deck<Item>
{
public:
	ItemDeck();

	Item* generateItem();
	std::vector<Item*> generateItems();
};