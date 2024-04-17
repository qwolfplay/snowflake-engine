//
// Created by WolfPlay on 4/15/2024.
//

#ifndef RPG_CHESTPLATE_H
#define RPG_CHESTPLATE_H

#include "Armor.abstract/Armor.h"

class Chestplate : public Armor
{
public:
    const float defenceMultiplier = 0.45;
    const float resistanceMultiplier = 0.49;

    Chestplate(
            std::string name,
            std::string description,
            float price,
            rarity rarity,
            float baseDefence,
            float baseResistance
        );

    ~Chestplate();

    [[nodiscard]] float calculateMeleeDamageReduction(float damage) const override;

    [[nodiscard]] float calculateMagicDamageReduction(float damage) const override;
};


#endif //RPG_CHESTPLATE_H
