#pragma once
#include <map>

#include "Deck.h"
#include "Monster.h"
#include "ItemDeck.h"
#include "ModifierDeck.h"


class MonsterDeck:Deck<Monster>
{
public:
	MonsterDeck();

	Monster* generateMonster();
};