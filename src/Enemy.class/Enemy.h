//
// Created by WolfPlay on 4/10/2024.
//

#ifndef POLYMORPHISM_ENEMY_H
#define POLYMORPHISM_ENEMY_H

class Enemy {
    float _health;
    unsigned int _maxHealth;
    unsigned int _armor;

public:
    Enemy(unsigned int health, unsigned int armor);
    ~Enemy() = default;

    [[nodiscard]] float getHealth() const;
    [[nodiscard]] unsigned int getArmor() const;
    [[nodiscard]] unsigned int getMaxHealth() const;

    void takeDamage(float damage);
};


#endif //POLYMORPHISM_ENEMY_H
