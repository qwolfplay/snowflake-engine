//
// Created by WolfPlay on 4/10/2024.
//

#include "Wand.h"

Wand::Wand(
        std::string name,
        std::string description,
        float price,
        rarity rarity,
        float damage,
        float armorPenetration,
        float attackSpeed
    ): Weapon(
            std::move(name),
            std::move(description),
            price,
            rarity,
            damage,
            armorPenetration,
            attackSpeed
            ) {};

Wand::~Wand() = default;

void Wand::attack(Enemy *target) {
    // TODO: damage formula
    target->takeDamage(getDamage());
}