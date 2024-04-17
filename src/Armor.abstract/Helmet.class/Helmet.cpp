//
// Created by WolfPlay on 4/15/2024.
//

#include "Helmet.h"

Helmet::Helmet(
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
        Armor::HELMET,
        rarity,
        baseDefence,
        baseResistance
)
{}

Helmet::~Helmet() = default;

float Helmet::calculateMeleeDamageReduction(float damage) const
{
    return (damage - (damage * (getBaseDefence() / 100.0))) * defenceMultiplier;
}

float Helmet::calculateMagicDamageReduction(float damage) const
{
    return (damage - (damage * (getBaseResistance() / 100.0))) * resistanceMultiplier;
}