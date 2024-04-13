//
// Created by WolfPlay on 4/10/2024.
//

#include <utility>

#include "Enemy.class/Enemy.h"
#include "Weapon.abstract/Weapon.h"

#include "Sword.h"

Sword::Sword(
        std::string name,
        std::string description,
        float price,
        rarity rarity,
        float damage,
        float armorPenetration,
        float attackSpeed
        ) :
    Weapon(std::move(name), std::move(description), price, rarity, damage, armorPenetration, attackSpeed) {};

Sword::~Sword() = default;

void Sword::attack(Enemy *target) {
    double damageAfterArmorPenetrationCalc = target->getArmor() * (Sword::getArmorPenetration() / 100.0);
    target->takeDamage(pow(getDamage() - (getDamage() * damageAfterArmorPenetrationCalc / 86.0), 1.15));
}