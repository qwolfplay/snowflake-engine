//
// Created by WolfPlay on 4/15/2024.
//

#include "Chestplate.h"

Chestplate::Chestplate(
        std::string name,
        std::string description,
        float price,
        rarity rarity,
        float baseDefence,
        float baseResistance
) : Armor(
        name,
        description,
        price,
        Armor::CHESTPLATE,
        rarity,
        baseDefence,
        baseResistance
),
    defenceMultiplier(0.45),
    resistanceMultiplier(0.49)
{}

Chestplate::~Chestplate() = default;

float Chestplate::getEffectiveDefence()
{
    return getBaseDefence() * defenceMultiplier;
}

float Chestplate::getEffectiveResistance()
{
    return getBaseResistance() * resistanceMultiplier;
}

float Chestplate::calculateMeleeDamageReduction(float damage) const
{
    return (damage - (damage * (getBaseDefence() / 100.0))) * defenceMultiplier;
}

float Chestplate::calculateMagicDamageReduction(float damage) const
{
    return (damage - (damage * (getBaseResistance() / 100.0))) * resistanceMultiplier;
}