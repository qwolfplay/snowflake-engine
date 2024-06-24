//
// Created by WolfPlay on 4/10/2024.
//

#ifndef POLYMORPHISM_ENEMY_H
#define POLYMORPHISM_ENEMY_H

#include "Player.class/Player.h"
#include "Armor.abstract/Helmet.class/Helmet.h"
#include "Armor.abstract/Chestplate.class/Chestplate.h"
#include "Armor.abstract/Leggings.class/Leggings.h"
#include "ArmorSet.class/ArmorSet.h"

class Enemy {
    float _health;
    unsigned int _maxHealth;
    ArmorSet *_armor;

public:
    Enemy(float health);

    Enemy(float health, Helmet *helmet, Chestplate *chestplate, Leggings *leggings);

    ~Enemy();

    [[nodiscard]] float getHealth() const;

    [[nodiscard]] unsigned int getMaxHealth() const;

    ArmorSet *getArmorPtr() const;

    void takeDamage(float damage, float armorPenetration);

    void takeRawDamage(float damage);

    bool isDead() const;
};


#endif //POLYMORPHISM_ENEMY_H
