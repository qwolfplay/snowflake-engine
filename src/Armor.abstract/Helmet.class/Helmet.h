//
// Created by WolfPlay on 4/15/2024.
//

#ifndef SNOWFLAKE_HELMET_H
#define SNOWFLAKE_HELMET_H

#include "Armor.abstract/Armor.h"

class Helmet : public Armor
{
public:
    const float defenceMultiplier;
    const float resistanceMultiplier;

    Helmet(
            std::string name,
            std::string description,
            float price,
            rarity rarity,
            float baseDefence,
            float baseResistance
    );

    ~Helmet();

    [[nodiscard]] float getEffectiveDefence() override;

    [[nodiscard]] float getEffectiveResistance() override;

    [[nodiscard]] float calculateMeleeDamageReduction(float damage) const override;

    [[nodiscard]] float calculateMagicDamageReduction(float damage) const override;
};


#endif //SNOWFLAKE_HELMET_H
