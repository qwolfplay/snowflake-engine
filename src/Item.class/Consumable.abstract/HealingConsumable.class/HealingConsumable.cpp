//
// Created by WolfPlay on 6/26/2024.
//

#include "HealingConsumable.h"

HealingConsumable::HealingConsumable(std::string name, std::string description, float price, Item::Rarity rarity, float healingAmount) :
    Consumable(std::move(name), std::move(description), price, ConsumableType::HEALING, rarity),
    _healingAmount(healingAmount) {}

float HealingConsumable::getHealingAmount() const
{
    return _healingAmount;
}

void HealingConsumable::use(Player *player)
{
    player->heal(_healingAmount);
}
