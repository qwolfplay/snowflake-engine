//
// Created by WolfPlay on 4/10/2024.
//

#include "Enemy.h"

#include "Exceptions/SlotEmptyException.h"
#include "Exceptions/SlotAlreadyOccupiedException.h"
#include "Exceptions/WeaponSlotEmptyException.h"
#include "ArmorSet.class/ArmorSet.h"

Enemy::Enemy(float health) :
_health(health),
_maxHealth(health),
_weapon(nullptr)
{
    _armor = new ArmorSet;
}

Enemy::Enemy(float health, Weapon *weapon) :
        _health(health),
        _maxHealth(health),
        _weapon(weapon)
{
    _armor = new ArmorSet;
}

Enemy::Enemy(float health, Weapon *weapon, Helmet *helmet, Chestplate *chestplate, Leggings *leggings) :
        _health(health),
        _maxHealth(health),
        _weapon(weapon)
{
    _armor = new ArmorSet(helmet, chestplate, leggings);
}

Enemy::~Enemy()
{
    delete _armor;
}

float Enemy::getHealth() const {
    return _health;
}

unsigned int Enemy::getMaxHealth() const {
    return _maxHealth;
}

ArmorSet *Enemy::getArmorPtr() const
{
    return _armor;
}

Weapon *Enemy::getWeaponPtr() const
{
    return _weapon;
}

void Enemy::takeDamage(float damage, float armorPenetration)
{
    float resultingDamage;
    if (armorPenetration > 75) { armorPenetration = 75; }

    resultingDamage = damage - (damage * (_armor->getDamageReduction(damage) *
            ArmorSet::calculateArmorPenetrationFactor(armorPenetration)));

    _health -= resultingDamage;
}

void Enemy::takeRawDamage(float damage)
{
    _health -= damage;
}

bool Enemy::isDead() const
{
    return _health <= 0;
}

void Enemy::attackPlayer(Player *target)
{
    if (!_weapon) { throw WeaponSlotEmptyException(); }
    _weapon->attackPlayer(target);
}
