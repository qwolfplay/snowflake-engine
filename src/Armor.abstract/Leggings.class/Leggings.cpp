//
// Created by WolfPlay on 4/15/2024.
//

#include "Leggings.h"

Leggings::Leggings(
        std::string name,
        std::string description,
        float price,
        Rarity rarity,
        float baseDefence,
        float baseResistance
) : Armor(
        name,
        description,
        price,
        Armor::LEGGINGS,
        rarity,
        baseDefence,
        baseResistance
),
    defenceMultiplier(0.325),
    resistanceMultiplier(0.16)
{}

Leggings::~Leggings() = default;

float Leggings::getEffectiveDefence()
{
    return getBaseDefence() * defenceMultiplier;
}

float Leggings::getEffectiveResistance()
{
    return getBaseResistance() * resistanceMultiplier;
}

float Leggings::calculateMeleeDamageReduction(float damage) const
{
    return (damage - (damage * (getBaseDefence() / 100.0))) * defenceMultiplier;
}

float Leggings::calculateMagicDamageReduction(float damage) const
{
    return (damage - (damage * (getBaseResistance() / 100.0))) * resistanceMultiplier;
}