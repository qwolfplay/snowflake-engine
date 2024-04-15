//
// Created by WolfPlay on 4/15/2024.
//

#ifndef RPG_HELMET_H
#define RPG_HELMET_H

#include "Armor.abstract/Armor.h"

class Helmet : public Armor
{
public:
    Helmet(std::string name,
           std::string description,
           float price,
           type type,
           rarity rarity,
           float baseDefence,
           float baseResistance);

    ~Helmet();

    float calculateMeleeDamageReduction(float damage) const override;

    float calculateMagicDamageReduction(float damage) const override;
};


#endif //RPG_HELMET_H
