#include "ItemDeck.h"

#include "Item.h"

ItemDeck::ItemDeck()
{

	database[new Weapon{ "The Sword of DOOM", 5 }] = 1;
	database[new UndeadWeapon{ "Stinky knife", 2 }] = 1;
	database[new UndeadWeapon{ "Holy grenade", 4 }] = 1;

	fill();
}

Item* ItemDeck::generateItem()
{
	return this->generate();
}

std::vector<Item*> ItemDeck::generateItems()
{
	return available;
}