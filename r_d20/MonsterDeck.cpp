#include <map>
#include <vector>

#include "MonsterDeck.h"
#include "Monster.h"
#include "Runaway.h"
#include "VictoryPolicy.h"
#include "ItemDeck.h"


MonsterDeck::MonsterDeck()
{
    database[new Monster{ "Crazy Joe", 4 }] = 3;
    database[new Monster{ "Shiva destructor", 20, Tribe::God, new Runaway_LevelDowngradeIf{2, 5} }] = 1;

    // Add Victory Policy to aply
    /*database[new Monster{ "Vampire", 15, Tribe::Undead, new Runaway_LevelDowngrade{1}, new VictoryPolicy_AddRandomItem{items} }] = 2;*/
    database[new Monster{ "Goblin", 1 }] = 5;
    database[new Monster{ "Dragon", 25, Tribe::Dragon, new Runaway_LevelDowngradeIf{3, 6} }] = 1;
    database[new Monster{ "Werewolf", 10, Tribe::Beast, new Runaway_LevelDowngrade{2} }] = 3;
    database[new Monster{ "Evil Witch", 12, Tribe::Human, new Runaway_LevelDowngradeIf{1, 4} }] = 2;
    database[new Monster{ "Lich King", 18, Tribe::Undead, new Runaway_LevelDowngrade{2} }] = 1;
    database[new Monster{ "Gremlin", 3 }] = 4;
    database[new Monster{ "Giant", 16, Tribe::Giant, new Runaway_LevelDowngradeIf{2, 5} }] = 1;
    database[new Monster{ "Hydra", 22, Tribe::Dragon, new Runaway_LevelDowngradeIf{3, 8} }] = 1;
    database[new Monster{ "Zombie", 7, Tribe::Undead, new Runaway_LevelDowngrade{1} }] = 3;
    database[new Monster{ "Basilisk", 11, Tribe::Reptile, new Runaway_LevelDowngradeIf{2, 5} }] = 2;
    database[new Monster{ "Demon Lord", 30, Tribe::Demon, new Runaway_LevelDowngradeIf{4, 7} }] = 1;
    database[new Monster{ "Orc Warlord", 14, Tribe::Orc, new Runaway_LevelDowngrade{2} }] = 2;
    database[new Monster{ "Elder Vampire", 19, Tribe::Undead, new Runaway_LevelDowngradeIf{3, 6} }] = 1;
    database[new Monster{ "Manticore", 13, Tribe::Beast, new Runaway_LevelDowngrade{2} }] = 1;
    database[new Monster{ "Troll", 9, Tribe::Beast, new Runaway_LevelDowngrade{1} }] = 3;
    database[new Monster{ "Dark Elf", 17, Tribe::Elf, new Runaway_LevelDowngradeIf{2, 5} }] = 1;
    database[new Monster{ "Minotaur", 8, Tribe::Beast, new Runaway_LevelDowngrade{1} }] = 2;
    database[new Monster{ "Harpy", 6, Tribe::Beast, new Runaway_LevelDowngradeIf{1, 3} }] = 2;
    database[new Monster{ "Cyclops", 21, Tribe::Giant, new Runaway_LevelDowngradeIf{3, 6} }] = 1;
    database[new Monster{ "Kraken", 26, Tribe::Beast, new Runaway_LevelDowngradeIf{4, 8} }] = 1;
}

Monster* MonsterDeck::generateMonster()
{
   return this->generate(true);
}