//
// Created by WolfPlay on 4/10/2024.
//

#include "Item.h"

Item::Item(std::string name, std::string description, float price, rarity rarity) :
    _name(std::move(name)),
    _description(std::move(description)),
    _price(price),
    _rarity(rarity)
{};

std::string Item::getName() const {
    return _name;
}

std::string Item::getDescription() const {
    return _description;
}

float Item::getPrice() const {
    return _price;
}

Item::rarity Item::getRarity() const {
    return _rarity;
}

void Item::setPrice(float price) {
    _price = price;
}