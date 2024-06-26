//
// Created by WolfPlay on 6/26/2024.
//

#ifndef SNOWFLAKE_CONSUMABLE_H
#define SNOWFLAKE_CONSUMABLE_H

#include "Item.class/Item.h"
#include "Player.class/Player.h"

class Consumable : public Item
{
public:
    enum ConsumableType {
        HEALING,
        FOOD,
        POTION
    };

protected:
    Consumable(std::string name, std::string description, float price, ConsumableType type, Item::Rarity rarity) :
        Item(std::move(name), std::move(description), price, ItemType::CONSUMABLE, rarity) {};

    virtual void use(Player *player) = 0;
};


#endif //SNOWFLAKE_CONSUMABLE_H
