#pragma once

#include <string>
#include <unordered_map>

enum class Tribe
{
	Human,
	Undead,
	Zombie,
	God,
	Count,
	Goliath,
	Giant,
	Dragon,
	Beast,
	Reptile,
	Demon,
	Orc,
	Elf,
};

inline std::string tribeToString(Tribe tribe) {
    static const std::unordered_map<Tribe, std::string> tribeStrings{
        {Tribe::Human, "Human"},
        {Tribe::Undead, "Undead"},
        {Tribe::Zombie, "Zombie"},
        {Tribe::God, "God"},
        {Tribe::Count, "Count"},
        {Tribe::Goliath, "Goliath"},
        {Tribe::Giant, "Giant"},
        {Tribe::Dragon, "Dragon"},
        {Tribe::Beast, "Beast"},
        {Tribe::Reptile, "Reptile"},
        {Tribe::Demon, "Demon"},
        {Tribe::Orc, "Orc"},
        {Tribe::Elf, "Elf"},
    };

    auto it = tribeStrings.find(tribe);
    if (it != tribeStrings.end()) {
        return it->second;
    }
    else {
        return "Unknown Tribe";
    }
}