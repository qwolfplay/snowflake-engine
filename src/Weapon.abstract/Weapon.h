//
// Created by WolfPlay on 4/10/2024.
//

#ifndef POLYMORPHISM_WEAPON_H
#define POLYMORPHISM_WEAPON_H

#include <random>

#include "Item.class/Item.h"
#include "Enemy.class/Enemy.h"

class Weapon : public Item {
private:
    float _baseDamage;
    float _armorPenetration;
    float _attackSpeed;
    float _critChance;
    float _critDamageMultiplier;

    std::random_device _rd;
    std::mt19937 _gen;

    bool isHitCritical();

public:
    Weapon(
        std::string name,
        std::string description,
        float price,
        type type,
        rarity rarity,
        float damage,
        float armorPenetration,
        float attackSpeed,
        float critDamage,
        float critDamagMult
        );

    ~Weapon() = default;

    [[nodiscard]] float getDamage() const;
    [[nodiscard]] float getArmorPenetration() const;
    [[nodiscard]] float getAttackSpeed() const;

    virtual float attack(Enemy *target);
};


#endif //POLYMORPHISM_WEAPON_H
