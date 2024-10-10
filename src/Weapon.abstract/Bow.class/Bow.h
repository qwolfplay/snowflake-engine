//
// Created by WolfPlay on 4/10/2024.
//

#ifndef SNOWFLAKE_BOW_H
#define SNOWFLAKE_BOW_H

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


#endif //SNOWFLAKE_BOW_H
