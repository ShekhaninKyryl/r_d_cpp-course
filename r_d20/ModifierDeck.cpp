#include "ModifierDeck.h"

#include "Modifier.h"

ModifierDeck::ModifierDeck()
{
	database[new SimpleModifier{ 1 }] = 3;
	database[new SimpleModifier{ 2 }] = 3;
	database[new SimpleModifier{ 3 }] = 2;
	database[new SimpleModifier{ 4 }] = 1;
	database[new SimpleModifier{ 5 }] = 1;
	database[new DoubleMunchkinLevel{}] = 1;
	database[new HalvesMonsterLevel{ Tribe::Undead }] = 2;
	database[new HalvesMonsterLevel{ Tribe::God }] = 2;
	database[new HalvesMonsterLevel{ Tribe::Demon }] = 2;


	fill();
}

Modifier* ModifierDeck::generateModifier()
{
	return this->generate();
}