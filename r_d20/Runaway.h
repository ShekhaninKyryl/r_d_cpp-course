#pragma once
#include <string>
#include <algorithm>

#include "Munchkin.h"
#include "Item.h"

class Runaway
{
public:
	virtual void apply(Munchkin* munchkin) = 0;

	virtual std::string getFullInfo() { return ""; }
};

class Runaway_LevelDowngrade : public Runaway
{
public:
	Runaway_LevelDowngrade(int level = 1) : m_levelToDowngrade(level) {}
	void apply(Munchkin* munchkin) override;


	std::string getFullInfo() { return "Level downgrade on " + std::to_string(m_levelToDowngrade); }

protected:
	int m_levelToDowngrade;
};

class Runaway_LevelDowngradeIf : public Runaway_LevelDowngrade
{
public:
	Runaway_LevelDowngradeIf(int level, int minimalMunchkinLevel)
		: Runaway_LevelDowngrade(level), m_minimalMunchkinLevelToApply(minimalMunchkinLevel) {}

	void apply(Munchkin* munchkin) override;

	std::string getFullInfo() { 
		return "Level downgrade on " + std::to_string(m_levelToDowngrade) 
			+ " if Munchkin level greater than " + std::to_string(m_minimalMunchkinLevelToApply); 
	}

private:
	int m_minimalMunchkinLevelToApply;
};

//Remove a card from hand(modifier) at random
class Runaway_ModifierFromHandRemoval : public Runaway
{
public:
	void apply(Munchkin* munchkin) override { 
		const int choice = std::rand() % munchkin->getModifiers().size();
		munchkin->removeModifierFromHand(choice);
	}

	std::string getFullInfo() { return "You will lose cards from your hand"; }

};


//Item 
// MUNCHKIN
// ACTIVE DECK
// DEACTIVED DECK

//Random item removal
class Runaway_ItemEquipedRemoval : public Runaway
{
public:
	//#TODO
	void apply(Munchkin* munchkin) override {
		const int choice = std::rand() % munchkin->getItems().size();
		munchkin->removeItemEquipped(choice);
	}

	std::string getFullInfo() { return "You will lose equipment"; }
};

//Remove equiped item from Outfit with biggest base power
class Runaway_BiggestBonusCardRemoval : public Runaway
{
public:
	void apply(Munchkin* munchkin) override {
		auto items = munchkin->getItems();
		if (items.empty()) {
			return;
		}

		auto maxPowerItem = std::max_element(items.begin(), items.end(),
			[](Item* a, Item* b) {
				return a->getBasePower() < b->getBasePower();
			});

		if (maxPowerItem != items.end()) {
			items.erase(maxPowerItem);
		}
	}

	std::string getFullInfo() { return "You will lose equipment with biggest base power"; }
};
