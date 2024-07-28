#pragma once
#include <string>
#include <algorithm>

#include "Munchkin.h"
#include "ItemDeck.h"


class VictoryPolicy
{
public:

    virtual ~VictoryPolicy() = default;
	virtual void apply(Munchkin* munchkin) = 0;
	virtual std::string getFullInfo() const { return ""; }
};


class VictoryPolicy_Items : public VictoryPolicy
{
public:
    VictoryPolicy_Items(ItemDeck* itemDeck) : items(itemDeck) {}

protected: 
    ItemDeck* items = nullptr;
};

class VictoryPolicy_AddRandomItem : public VictoryPolicy_Items
{
public:

    void apply(Munchkin* munchkin) override {
        auto item = items->generateItem();
        if (item == nullptr) return;
        munchkin->addItem(item);
    }

    std::string getFullInfo() const override { return "Add Item for munchkin"; }
};