//
// Created by WolfPlay on 4/10/2024.
//

#include <utility>
#include <cmath>

#include "Enemy.class/Enemy.h"
#include "Weapon.abstract/Weapon.h"

#include "Sword.h"

Sword::Sword(
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
        35.0f,
        1.83f
) {}

Sword::~Sword() = default;

void Sword::attack(Enemy *target) {
    target->takeDamage(Sword::getDamage(), Sword::getArmorPenetration());
}