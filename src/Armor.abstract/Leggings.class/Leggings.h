//
// Created by WolfPlay on 4/15/2024.
//

#ifndef SNOWFLAKE_LEGGINGS_H
#define SNOWFLAKE_LEGGINGS_H

#include "Armor.abstract/Armor.h"

class Leggings : public Armor
{
public:
    const float defenceMultiplier;
    const float resistanceMultiplier;

    Leggings(
            std::string name,
            std::string description,
            float price,
            rarity rarity,
            float baseDefence,
            float baseResistance
        );

    ~Leggings();

    [[nodiscard]] float getEffectiveDefence() override;

    [[nodiscard]] float getEffectiveResistance() override;

    [[nodiscard]] float calculateMeleeDamageReduction(float damage) const override;

    [[nodiscard]] float calculateMagicDamageReduction(float damage) const override;
};


#endif //SNOWFLAKE_LEGGINGS_H
