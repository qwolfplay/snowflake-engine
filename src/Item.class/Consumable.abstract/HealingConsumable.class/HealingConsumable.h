//
// Created by WolfPlay on 6/26/2024.
//

#ifndef SNOWFLAKE_HEALINGCONSUMABLE_H
#define SNOWFLAKE_HEALINGCONSUMABLE_H

#include "../Consumable.h"

class HealingConsumable : public Consumable
{
    float _healingAmount;
public:
    HealingConsumable(std::string name, std::string description, float price, Rarity rarity, float healingAmount);

    [[nodiscard]] float getHealingAmount() const;

    void use(Player *player) override;
};


#endif //SNOWFLAKE_HEALINGCONSUMABLE_H
