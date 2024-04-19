//
// Created by WolfPlay on 4/10/2024.
//

#ifndef POLYMORPHISM_ENEMY_H
#define POLYMORPHISM_ENEMY_H

#include "Player.class/Player.h"

class Enemy {
    float _health;
    unsigned int _maxHealth;
    Player::ArmorSet *_armor;

public:
    Enemy(float health);
    ~Enemy() = default;

    [[nodiscard]] float getHealth() const;

    [[nodiscard]] unsigned int getMaxHealth() const;

    float getEffectiveDefence();

    float getEffectiveResistance();

    [[nodiscard]] Helmet *getHelmetPtr() const;

    [[nodiscard]] Chestplate *getChestplatePtr() const;

    [[nodiscard]] Leggings *getLeggingsPtr() const;

    void takeDamage(float damage, float armorPenetration);

    void takeRawDamage(float damage);
};


#endif //POLYMORPHISM_ENEMY_H
