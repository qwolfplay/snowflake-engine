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
        rarity rarity,
        float damage,
        float armorPenetration,
        float attackSpeed
        ) : Weapon(std::move(name), std::move(description), price, rarity, damage, armorPenetration, attackSpeed) {};

Bow::~Bow() = default;

void Bow::attack(Enemy *target) {
    // TODO: damage formula
    target->takeDamage(getDamage());
}