//
// Created by WolfPlay on 4/10/2024.
//

#ifndef POLYMORPHISM_BOW_H
#define POLYMORPHISM_BOW_H

#include "Weapon.abstract/Weapon.h"

class Bow : public Weapon {
public:
    Bow(
        std::string name,
        std::string description,
        float price,
        type type,
        rarity rarity,
        float damage,
        float armorPenetration,
        float attackSpeed
        );
    ~Bow();
    void attack(Enemy *target) override;
};


#endif //POLYMORPHISM_BOW_H
