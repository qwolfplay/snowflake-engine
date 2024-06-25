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
#include "Weapon.abstract/Weapon.h"

class Player;
class Weapon;
class Enemy {
    float _health;
    unsigned int _maxHealth;

    ArmorSet *_armor;
    Weapon *_weapon;

public:
    explicit Enemy(float health);

    Enemy(float health, Weapon *weapon);

    Enemy(float health, Weapon *weapon, Helmet *helmet, Chestplate *chestplate, Leggings *leggings);

    ~Enemy();

    [[nodiscard]] float getHealth() const;

    [[nodiscard]] unsigned int getMaxHealth() const;

    [[nodiscard]] ArmorSet *getArmorPtr() const;

    [[nodiscard]] Weapon *getWeaponPtr() const;

    void takeDamage(float damage, float armorPenetration);

    void takeRawDamage(float damage);

    [[nodiscard]] bool isDead() const;

    void attackPlayer(Player *target);
};


#endif //POLYMORPHISM_ENEMY_H
