//
// Created by WolfPlay on 4/10/2024.
//

#include "Wand.h"

Wand::Wand(
        std::string name,
        std::string description,
        float price,
        type type,
        rarity rarity,
        float damage,
        float armorPenetration,
        float attackSpeed
): Weapon(
        std::move(name),
        std::move(description),
        price,
        type,
        rarity,
        damage,
        armorPenetration,
        attackSpeed,
        62.0f,
        1.62f
) {}

Wand::~Wand() = default;

void Wand::attack(Enemy *target) {
    // TODO: damage formula
    target->takeDamage(getDamage(), 0);
}