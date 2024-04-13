//
// Created by WolfPlay on 4/10/2024.
//

#ifndef POLYMORPHISM_WEAPON_H
#define POLYMORPHISM_WEAPON_H

#include "Item.class/Item.h"
#include "Enemy.class/Enemy.h"

class Weapon : public Item {
private:
    float _damage;
    float _armorPenetration;
    float _attackSpeed;

public:
    Weapon(
        std::string name,
        std::string description,
        float price,
        rarity rarity,
        float damage,
        float armorPenetration,
        float attackSpeed
        );

    ~Weapon() = default;

    [[nodiscard]] float getDamage() const;
    [[nodiscard]] float getArmorPenetration() const;
    [[nodiscard]] float getAttackSpeed() const;

    virtual void attack(Enemy *target);
};


#endif //POLYMORPHISM_WEAPON_H
