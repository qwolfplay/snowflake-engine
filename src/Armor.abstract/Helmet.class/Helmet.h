//
// Created by WolfPlay on 4/15/2024.
//

#ifndef RPG_HELMET_H
#define RPG_HELMET_H

#include "Armor.abstract/Armor.h"

class Helmet : public Armor
{
public:
    const float defenceMultiplier = 0.225;
    const float resistanceMultiplier = 0.35;

    Helmet(
            std::string name,
            std::string description,
            float price,
            rarity rarity,
            float baseDefence,
            float baseResistance
    );

    ~Helmet();

    [[nodiscard]] float calculateMeleeDamageReduction(float damage) const override;

    [[nodiscard]] float calculateMagicDamageReduction(float damage) const override;
};


#endif //RPG_HELMET_H
