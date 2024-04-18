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
        float attackSpeed,
        float critChance,
        float critDamageMult
) : Weapon(
        std::move(name),
        std::move(description),
        price,
        type,
        rarity,
        damage,
        armorPenetration,
        attackSpeed,
        critChance,
        critDamageMult
) {}

Sword::~Sword() = default;

void Sword::attack(Enemy *target) {
    // TODO: Figure out a way to calculate armor penetration without damaging target in fucntion (if possible)
    // * Maybe 1: Pass weapon to target and calc it on the target side
    // * Maybe 2: Pass armor of target into Weapon::attack() (like its now)

    double damageAfterArmorPenetrationCalc = target->getArmor() * (Sword::getArmorPenetration() / 100.0);
    target->takeDamage(pow(getDamage() - (getDamage() * damageAfterArmorPenetrationCalc / 86.0), 1.15));
}