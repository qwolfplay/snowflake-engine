//
// Created by WolfPlay on 4/10/2024.
//

#include <stdexcept>
#include <string>

#include "Player.h"

Player::Player(std::string name, float health, float armor, unsigned short int maxInventorySize) :
        _name(std::move(name)),
        _maxHealth(health),
        _maxItemInventorySize(maxInventorySize)
{
    _health = _maxHealth;
    _inventory = new InventorySlot[maxInventorySize];
    _itemCount = 0;
    for (int i = 0; i < maxInventorySize; i++) {
        _inventory[i].itemPtr = nullptr;
        _inventory[i].isOccupied = false;
    }

    _armor->helmet = nullptr;
    _armor->chestplate = nullptr;
    _armor->leggings = nullptr;
    _armor->isHelmetEquipped = false;
    _armor->isChestplateEquipped = false;
    _armor->isLeggingsEquipped = false;

}

Player::~Player()
{
    delete[] _inventory;
}

std::string Player::getName()
{
    return _name;
}

float Player::getHealth() const
{
    return _health;
}

float Player::getMaxHealth() const
{
    return _maxHealth;
}

float Player::getArmor() const
{
    return _armor;
}

void Player::addItemToInventory(Item *item)
{
    if (_itemCount < _maxItemInventorySize) {
        for (int i = 0; i < _maxItemInventorySize; i++) {
            if (!_inventory[i].isOccupied) {
                _inventory[i].itemPtr = item;
                _inventory[i].isOccupied = true;
                _itemCount++;
                break;
            }
        }
    } else {
        throw SlotEmptyException();
    }
}


void Player::removeItemFromInventory(unsigned short int index)
{
//    _itemInventory.erase(_itemInventory.begin() + index);
    if (_inventory[index].isOccupied) {
        _inventory[index].itemPtr = nullptr;
        _inventory[index].isOccupied = false;
        _itemCount--;
    } else {
        throw SlotEmptyException();
    }
}


int Player::getItemCount()
{
    return _itemCount;
}


Item *Player::getItem(int index)
{
    return _inventory[index].itemPtr;
}

void Player::equipWeapon(int index)
{
    if (!_inventory[index].isOccupied) {
        throw SlotEmptyException();
    } else {
        if (_inventory[index].itemPtr->getType() == Item::type::WEAPON) {
            _equippedWeapon = (Weapon *) (_inventory[index].itemPtr);
        } else {
            throw WrongItemTypeException();
        }

    }

}

Weapon *Player::getEquippedWeapon()
{
    return _equippedWeapon;
}
