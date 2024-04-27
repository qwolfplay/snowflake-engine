//
// Created by WolfPlay on 4/10/2024.
//

#include "Bow.h"

#include "Weapon.abstract/Weapon.h"
#include "Enemy.class/Enemy.h"

Bow::Bow(
        std::string name,
        std::string description,
        float price,
        type type,
        rarity rarity,
        float damage,
        float armorPenetration,
        float attackSpeed
) : Weapon(
        std::move(name),
        std::move(description),
        price,
        type,
        rarity,
        damage,
        armorPenetration,
        attackSpeed,
        24,
        1.8
) {};

Bow::~Bow() = default;

void Bow::attack(Enemy *target) {
    // TODO: damage formula
    target->takeDamage(getDamage(), 0);
}