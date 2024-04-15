//
// Created by WolfPlay on 4/14/2024.
//

#include "Armor.h"

Armor::Armor(std::string name,
        std::string description,
        float price,
             armorType type,
        rarity rarity,
        float baseDefence,
        float baseResistance)
    : Item(std::move(name),
            std::move(description),
            price,
           Item::ARMOR,
            rarity),
      _type(type),
        _baseDefence(baseDefence),
        _baseResistance(baseResistance) {};

Armor::~Armor() = default;

float Armor::getBaseDefence() const {
    return _baseDefence;
}

float Armor::getBaseResistance() const {
    return _baseResistance;
}

float Armor::calculateMeleeDamageReduction(float damage) const {
    return damage * (_baseDefence / 100.0);
}

float Armor::calculateMagicDamageReduction(float damage) const {
    return damage * (_baseResistance / 100.0);
}
