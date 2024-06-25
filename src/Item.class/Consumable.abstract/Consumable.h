//
// Created by WolfPlay on 6/26/2024.
//

#ifndef SNOWFLAKE_CONSUMABLE_H
#define SNOWFLAKE_CONSUMABLE_H

#include "Item.class/Item.h"

class Consumable : public Item
{
public:
    enum ConsumableType {
        HEALING,
        FOOD,
        POTION
    };

protected:
    virtual void use() = 0;
};


#endif //SNOWFLAKE_CONSUMABLE_H
