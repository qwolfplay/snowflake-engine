//
// Created by WolfPlay on 4/10/2024.
//

#include <stdexcept>
#include <string>
#include <vector>

#include "Player.h"

Player::Player(std::string name, float health, float armor, unsigned short int maxInventorySize) :
        _name(std::move(name)),
        _maxHealth(health),
        _inventorySize(maxInventorySize)
{
    _health = _maxHealth;
    _inventory = new InventorySlot[maxInventorySize];
    for (int i = 0; i < maxInventorySize; i++) {
        _inventory[i].itemPtr = nullptr;
        _inventory[i].isOccupied = false;
    }
    _itemCount = 0;

    _armor = new ArmorSet;
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

void Player::addItemToInventory(Item *item)
{
    if (_itemCount < _inventorySize) {
        for (int i = 0; i < _inventorySize; i++) {
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


float Player::getEffectiveDefence()
{
    float effective = 0;
    if (_armor->isHelmetEquipped)       { effective += _armor->helmet->getEffectiveDefence(); }
    if (_armor->isChestplateEquipped)   { effective += _armor->chestplate->getEffectiveDefence(); }
    if (_armor->isLeggingsEquipped)     { effective += _armor->leggings->getEffectiveDefence(); }

    return effective;
}

float Player::getEffectiveResistance()
{
    float effective = 0;
    if (_armor->isHelmetEquipped)       { effective += _armor->helmet->getEffectiveResistance(); }
    if (_armor->isChestplateEquipped)   { effective += _armor->chestplate->getEffectiveResistance(); }
    if (_armor->isLeggingsEquipped)     { effective += _armor->leggings->getEffectiveResistance(); }

    return effective;
}

int Player::getItemCount() const
{
    return _itemCount;
}

std::vector<unsigned short int> Player::getFreeSlots() const
{
    if (_itemCount >= _inventorySize) {
        throw InventoryFullException();
    }

    std::vector<unsigned short int> freeSlots{};

    for (int i = 0; i < _inventorySize; i++) {
        if (!_inventory[i].isOccupied) {
            freeSlots.push_back(i);
        }
    }

    return freeSlots;
}

Item *Player::getItemPtr(unsigned short int index)
{
    if (_inventory[index].isOccupied) {
        return _inventory[index].itemPtr;
    } else {
        throw SlotEmptyException();
    }
}

void Player::equipWeapon(unsigned short int index)
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

void Player::equipHelmet(unsigned short int index)
{
    if (!_inventory[index].isOccupied) { throw SlotEmptyException(); }
    if (_inventory[index].itemPtr->getType() != Item::type::ARMOR ||
        ((Armor *) _inventory[index].itemPtr)->getArmorType() != Armor::HELMET) {
        throw WrongItemTypeException();
    }

    _armor->helmet = (Helmet *) _inventory[index].itemPtr;
    _armor->isHelmetEquipped = true;

    _inventory[index].itemPtr = nullptr;
    _inventory[index].isOccupied = false;
}

void Player::equipChestplate(unsigned short int index)
{
    if (!_inventory[index].isOccupied) { throw SlotEmptyException(); }
    if (_inventory[index].itemPtr->getType() != Item::type::ARMOR ||
        ((Armor *) _inventory[index].itemPtr)->getArmorType() != Armor::CHESTPLATE) {
        throw WrongItemTypeException();
    }

    _armor->chestplate = (Chestplate *) _inventory[index].itemPtr;
    _armor->isChestplateEquipped = true;

    _inventory[index].itemPtr = nullptr;
    _inventory[index].isOccupied = false;
}

void Player::equipLeggings(unsigned short int index)
{
    if (!_inventory[index].isOccupied) { throw SlotEmptyException(); }
    if (_inventory[index].itemPtr->getType() != Item::type::ARMOR ||
        ((Armor *) _inventory[index].itemPtr)->getArmorType() != Armor::LEGGINGS) {
        throw WrongItemTypeException();
    }

    _armor->leggings = (Leggings *) _inventory[index].itemPtr;
    _armor->isLeggingsEquipped = true;

    _inventory[index].itemPtr = nullptr;
    _inventory[index].isOccupied = false;
}

Helmet *Player::getHelmetPtr() const
{
    if (!_armor->isHelmetEquipped) { throw SlotEmptyException(); }
    return _armor->helmet;
}

Chestplate *Player::getChestplatePtr() const
{
    if (!_armor->isChestplateEquipped) { throw SlotEmptyException(); }
    return _armor->chestplate;
}

Leggings *Player::getLeggingsPtr() const
{
    if (!_armor->isLeggingsEquipped) { throw SlotEmptyException(); }
    return _armor->leggings;
}

void Player::unequipHelmet()
{
    if (!_armor->isHelmetEquipped) { throw SlotEmptyException(); }

    if (_itemCount >= _inventorySize) {
        throw InventoryFullException();
    }

    unsigned short int emptySlotIndex = 0;
    for (unsigned short int i = 0; i < _inventorySize; ++i) {
        if (!_inventory[i].isOccupied) {
            emptySlotIndex = i;
            break;
        }
    }

    _inventory[emptySlotIndex].itemPtr = (Item *) _armor->helmet;
    _inventory[emptySlotIndex].isOccupied = true;
    _armor->helmet = nullptr;
    _armor->isHelmetEquipped = false;

}

void Player::unequipChestplate()
{
    if (!_armor->isChestplateEquipped) { throw SlotEmptyException(); }

    if (_itemCount >= _inventorySize) {
        throw InventoryFullException();
    }

    unsigned short int emptySlotIndex = 0;
    for (unsigned short int i = 0; i < _inventorySize; ++i) {
        if (!_inventory[i].isOccupied) {
            emptySlotIndex = i;
            break;
        }
    }

    _inventory[emptySlotIndex].itemPtr = (Item *) _armor->chestplate;
    _inventory[emptySlotIndex].isOccupied = true;
    _armor->chestplate = nullptr;
    _armor->isChestplateEquipped = false;
}

void Player::unequipLeggings()
{
    if (!_armor->isLeggingsEquipped) { throw SlotEmptyException(); }

    if (_itemCount >= _inventorySize) {
        throw InventoryFullException();
    }

    unsigned short int emptySlotIndex = 0;
    for (unsigned short int i = 0; i < _inventorySize; ++i) {
        if (!_inventory[i].isOccupied) {
            emptySlotIndex = i;
            break;
        }
    }

    _inventory[emptySlotIndex].itemPtr = (Item *) _armor->leggings;
    _inventory[emptySlotIndex].isOccupied = true;
    _armor->leggings = nullptr;
    _armor->isLeggingsEquipped = false;
}
