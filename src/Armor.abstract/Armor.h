//
// Created by WolfPlay on 4/14/2024.
//

#ifndef RPG_ARMOR_H
#define RPG_ARMOR_H

#include "Item.class/Item.h"

class Armor : public Item
{
    const float _baseDefence;
    const float _baseResistance;

public:
    Armor(std::string name,
          std::string description,
          float price,
          type type,
          rarity rarity,
          float baseDefence,
          float baseResistance);

    ~Armor();

    [[nodiscard]] float getBaseDefence() const;

    [[nodiscard]] float getBaseResistance() const;

    virtual float calculateMeleeDamageReduction(float damage) const;

    virtual float calculateMagicDamageReduction(float damage) const;

};


#endif //RPG_ARMOR_H
