//
// Created by WolfPlay on 4/10/2024.
//

#include "Enemy.h"

Enemy::Enemy(unsigned int health,unsigned int armor) :
    _health(health),
    _maxHealth(health),
    _armor(armor)
{};

float Enemy::getHealth() const {
    return _health;
}

unsigned int Enemy::getMaxHealth() const {
    return _maxHealth;
}

unsigned int Enemy::getArmor() const {
    return _armor;
}

void Enemy::takeDamage(float damage) {
    // TODO: expand this function to include armor calculations
    _health -= damage;
}

