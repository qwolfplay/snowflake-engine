//
// Created by WolfPlay on 4/15/2024.
//

#include "Helmet.h"

Helmet::Helmet(
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
        Armor::HELMET,
        rarity,
        baseDefence,
        baseResistance
),
    defenceMultiplier(0.225),
    resistanceMultiplier(0.35)
{}

Helmet::~Helmet() = default;

float Helmet::getEffectiveDefence()
{
    return getBaseDefence() * defenceMultiplier;
}

float Helmet::getEffectiveResistance()
{
    return getBaseResistance() * resistanceMultiplier;
}

float Helmet::calculateMeleeDamageReduction(float damage) const
{
    return (damage - (damage * (getBaseDefence() / 100.0))) * defenceMultiplier;
}

float Helmet::calculateMagicDamageReduction(float damage) const
{
    return (damage - (damage * (getBaseResistance() / 100.0))) * resistanceMultiplier;
}