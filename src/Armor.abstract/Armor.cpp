//
// Created by WolfPlay on 4/14/2024.
//

#include "Armor.h"

Armor::Armor(
        std::string name,
        std::string description,
        float price,
        armorType type,
        rarity rarity,
        float baseDefence,
        float baseResistance
) : Item(
        std::move(name),
        std::move(description),
        price,
       Item::ARMOR,
        rarity
),
    _type(type),
    _baseDefence(baseDefence),
    _baseResistance(baseResistance),
    defenceMultiplier(1.0),
    resistanceMultiplier(1.0)
{}

Armor::~Armor() = default;

float Armor::getBaseDefence() const {
    return _baseDefence;
}

float Armor::getBaseResistance() const {
    return _baseResistance;
}

Armor::armorType Armor::getArmorType() const
{
    return _type;
}

float Armor::getEffectiveDefence()
{
    return _baseDefence * defenceMultiplier;
}

float Armor::getEffectiveResistance()
{
    return _baseResistance * resistanceMultiplier;
}

float Armor::calculateMeleeDamageReduction(float damage) const {
    return (damage * (_baseDefence / 100.0)) * defenceMultiplier;
}

float Armor::calculateMagicDamageReduction(float damage) const {
    return (damage * (_baseResistance / 100.0)) * resistanceMultiplier;
}
