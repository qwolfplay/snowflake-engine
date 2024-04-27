//
// Created by WolfPlay on 4/10/2024.
//

#include "Enemy.h"

#include "Exceptions/SlotEmptyException.h"
#include "Exceptions/SlotAlreadyOccupiedException.h"
#include "ArmorSet.class/ArmorSet.h"

Enemy::Enemy(float health) :
    _health(health),
    _maxHealth(health)
{
    _armor = new ArmorSet;
};

Enemy::Enemy(float health, Helmet *helmet, Chestplate *chestplate, Leggings *leggings) :
        _health(health),
        _maxHealth(health)
{
    _armor = new ArmorSet(helmet, chestplate, leggings);
};

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

void Enemy::takeDamage(float damage, float armorPenetration)
{
    // TODO: expand this function to include armor calculations
    float resultingDamage = damage;
    float damageReductionFactor =
            _armor->getEffectiveDefence() - (_armor->getEffectiveDefence() * armorPenetration / 100.0);

}

void Enemy::takeRawDamage(float damage)
{
    _health -= damage;
}
