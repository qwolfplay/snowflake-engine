//
// Created by WolfPlay on 4/15/2024.
//

#include "Helmet.h"

Helmet::Helmet(std::string name,
               std::string description,
               float price,
               type type,
               rarity rarity,
               float baseDefence,
               float baseResistance)
        : Armor(name, description, price, type, rarity, baseDefence, baseResistance)
{
}

Helmet::~Helmet() = default;

float Helmet::calculateMeleeDamageReduction(float damage) const
{
    return (damage - (damage * (getBaseDefence() / 100.0))) * 0.45;
}

float Helmet::calculateMagicDamageReduction(float damage) const
{
    return (damage - (damage * (getBaseResistance() / 100.0))) * 0.49;
}