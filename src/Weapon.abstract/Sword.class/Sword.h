//
// Created by WolfPlay on 4/10/2024.
//

#ifndef POLYMORPHISM_SWORD_H
#define POLYMORPHISM_SWORD_H

#include "Enemy.class/Enemy.h"
#include "Item.class/Item.h"
#include "Weapon.abstract/Weapon.h"

class Sword : public Weapon {
public:
    Sword(
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
        );
    ~Sword();
    void attack(Enemy *target) override;
};


#endif //POLYMORPHISM_SWORD_H
