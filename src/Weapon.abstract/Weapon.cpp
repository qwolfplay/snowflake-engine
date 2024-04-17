//
// Created by WolfPlay on 4/10/2024.
//

#include "Weapon.h"

#include <utility>

Weapon::Weapon(
        std::string name,
        std::string description,
        float price,
        type type,
        rarity rarity,
        float damage,
        float armorPenetration,
        float attackSpeed
) : Item(
        std::move(name),
        std::move(description),
        price,
        type,
        rarity
),
        _damage(damage),
        _armorPenetration(armorPenetration),
        _attackSpeed(attackSpeed)
{}

float Weapon::getDamage() const {
    return _damage;
}

float Weapon::getArmorPenetration() const {
    return _armorPenetration;
}

float Weapon::getAttackSpeed() const {
    return _attackSpeed;
}

void Weapon::attack(Enemy *target) {
    // TODO: expand function to include armor calculations
    target->takeDamage(_damage);
}