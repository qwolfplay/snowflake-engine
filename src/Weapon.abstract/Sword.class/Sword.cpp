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
        Rarity rarity,
        float damage,
        float armorPenetration,
        float attackSpeed
) : Weapon(
        std::move(name),
        std::move(description),
        price,
        Item::ItemType::WEAPON,
        rarity,
        damage,
        armorPenetration,
        attackSpeed,
        35.0f,
        1.83f
) {}

Sword::~Sword() = default;