//
// Created by WolfPlay on 4/10/2024.
//

#ifndef SNOWFLAKE_WAND_H
#define SNOWFLAKE_WAND_H

#include "Weapon.abstract/Weapon.h"

class Wand : public Weapon {
public:
    Wand(
        std::string name,
        std::string description,
        float price,
        type type,
        rarity rarity,
        float damage,
        float armorPenetration,
        float attackSpeed
    );
    ~Wand();
    void attack(Enemy *target) override;
};


#endif //SNOWFLAKE_WAND_H
