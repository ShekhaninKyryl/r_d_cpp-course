#pragma once
#include <vector>

#include "Deck.h"

//forward declaration to not include header into header which will increase compilation time
class Modifier;

class ModifierDeck:Deck<Modifier>
{
public:
	ModifierDeck();

	Modifier* generateModifier();

	std::vector<Modifier*> generateModifiers() { return available; }
};