//
// Created by WolfPlay on 4/10/2024.
//

#include "Enemy.h"

#include "Player.class/Player.h"

Enemy::Enemy(float health) :
    _health(health),
    _maxHealth(health)
{
    _armor = new Player::ArmorSet;
    _armor->helmet = nullptr;
    _armor->chestplate = nullptr;
    _armor->leggings = nullptr;
    _armor->isHelmetEquipped = false;
    _armor->isChestplateEquipped = false;
    _armor->isLeggingsEquipped = false;
};

float Enemy::getHealth() const {
    return _health;
}

unsigned int Enemy::getMaxHealth() const {
    return _maxHealth;
}

float Enemy::getEffectiveDefence()
{
    float effective = 0;
    if (_armor->isHelmetEquipped) { effective += _armor->helmet->getEffectiveDefence(); }
    if (_armor->isChestplateEquipped) { effective += _armor->chestplate->getEffectiveDefence(); }
    if (_armor->isLeggingsEquipped) { effective += _armor->leggings->getEffectiveDefence(); }

    return effective;
}

float Enemy::getEffectiveResistance()
{
    float effective = 0;
    if (_armor->isHelmetEquipped) { effective += _armor->helmet->getEffectiveResistance(); }
    if (_armor->isChestplateEquipped) { effective += _armor->chestplate->getEffectiveResistance(); }
    if (_armor->isLeggingsEquipped) { effective += _armor->leggings->getEffectiveResistance(); }

    return effective;
}

Helmet *Enemy::getHelmetPtr() const
{
    if (!_armor->isHelmetEquipped) { throw Player::SlotEmptyException(); }
    return _armor->helmet;
}

Chestplate *Enemy::getChestplatePtr() const
{
    if (!_armor->isChestplateEquipped) { throw Player::SlotEmptyException(); }
    return _armor->chestplate;
}

Leggings *Enemy::getLeggingsPtr() const
{
    if (!_armor->isLeggingsEquipped) { throw Player::SlotEmptyException(); }
    return _armor->leggings;
}

void Enemy::takeDamage(float damage, float armorPenetration)
{
    // TODO: expand this function to include armor calculations
    float resultingDamage = damage;
    float damageReductionFactor = armor - (armor * armorPenetration / 100.0)

}

void Enemy::takeRawDamage(float damage)
{
    _health -= damage;
}
