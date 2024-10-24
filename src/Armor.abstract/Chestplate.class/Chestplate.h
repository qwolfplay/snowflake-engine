//
// Created by WolfPlay on 4/15/2024.
//

#ifndef SNOWFLAKE_CHESTPLATE_H
#define SNOWFLAKE_CHESTPLATE_H

#include "Armor.abstract/Armor.h"

class Chestplate : public Armor
{
public:
    const float defenceMultiplier;
    const float resistanceMultiplier;

    Chestplate(
            std::string name,
            std::string description,
            float price,
            rarity rarity,
            float baseDefence,
            float baseResistance
        );

    ~Chestplate();

    [[nodiscard]] float getEffectiveDefence() override;

    [[nodiscard]] float getEffectiveResistance() override;

    [[nodiscard]] float calculateMeleeDamageReduction(float damage) const override;

    [[nodiscard]] float calculateMagicDamageReduction(float damage) const override;
};


#endif //SNOWFLAKE_CHESTPLATE_H
