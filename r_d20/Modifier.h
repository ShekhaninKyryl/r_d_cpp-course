#pragma once
#include <string>

#include "Monster.h"
#include "Munchkin.h"
#include "Tribe.h"


class Modifier
{
public:
	virtual void apply(Munchkin* munchkin, Monster* monster) = 0;
	virtual int getMunchkinModifier() const { return m_munchkinPowerChange; }
	virtual int getMonsterModifier() const { return m_monsterPowerChange; }

	virtual std::string getFullInfo() const { return ""; }

protected:
	int m_munchkinPowerChange = 0;
	int m_monsterPowerChange = 0;
};

class SimpleModifier : public Modifier
{
public:
	SimpleModifier(int powerBoost) : m_powerBoost(powerBoost) {}

	virtual void apply(Munchkin*, Monster*) override
	{
		m_munchkinPowerChange = m_powerBoost;
	}

	virtual std::string getFullInfo() const
	{
		return "Munchkin power + " + std::to_string(m_powerBoost);
	}

private:
	int m_powerBoost;
};

class DoubleMunchkinLevel : public Modifier
{
public:
	virtual void apply(Munchkin* munchkin, Monster*) override
	{
		m_munchkinPowerChange = munchkin->getLevel();
	}

	virtual std::string getFullInfo() const override
	{
		return "Double Munchkin level!";
	}
};

class HalvesMonsterLevel : public Modifier
{
public:
	//#TODO: cut monster's power in 2 if he is of type tribe
	HalvesMonsterLevel(Tribe tribe) {
		m_tribe = tribe;
	}
	virtual void apply(Munchkin*, Monster* monster) override {
		if (monster->getTribe() == m_tribe)
		m_monsterPowerChange = monster->getLevel() / 2;
	};

	virtual std::string getFullInfo() const override { return "Cut monster's power in 2 if it is " + tribeToString(m_tribe); };

private: 
	Tribe m_tribe;

};

//#TODO: Add unique modifier munchkin/monster specific
//Absolutely unique (for example add Munckin class: gnome, elph, human, sex: man, woman, non-binary