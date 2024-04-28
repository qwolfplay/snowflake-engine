//
// Created by WolfPlay on 4/10/2024.
//

#include "Player.h"

#include <stdexcept>
#include <string>
#include <vector>

#include "Item.class/item.h"
#include "Weapon.abstract/Weapon.h"
#include "ArmorSet.class/ArmorSet.h"
#include "Exceptions/SlotEmptyException.h"
#include "Exceptions/SlotAlreadyOccupiedException.h"
#include "Exceptions/InventoryFullException.h"
#include "Exceptions/WrongItemTypeException.h"


Player::Player(std::string name, float health, unsigned short int maxInventorySize) :
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
    _equippedWeapon = nullptr;
}

Player::~Player()
{
    delete[] _inventory;
    delete _armor;
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

ArmorSet *Player::getArmorSetPtr()
{
    return _armor;
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

unsigned short int Player::getFirstFreeSlot()
{
    if (_itemCount >= _inventorySize) {
        throw InventoryFullException();
    }

    for (int i = 0; i < _inventorySize; i++) {
        if (!_inventory[i].isOccupied) {
            return i;
        }
    }

    return 0;
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
    if (_equippedWeapon == nullptr) {
        throw SlotEmptyException();
    }
    return _equippedWeapon;
}

void Player::equipHelmet(unsigned short int index)
{
    if (!_inventory[index].isOccupied) { throw SlotEmptyException(); }
    if (_inventory[index].itemPtr->getType() != Item::type::ARMOR ||
        ((Armor *) _inventory[index].itemPtr)->getArmorType() != Armor::HELMET) {
        throw WrongItemTypeException();
    }

    _armor->equipHelmet((Helmet *) _inventory[index].itemPtr);

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

    _armor->equipChestplate((Chestplate *) _inventory[index].itemPtr);

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

    _armor->equipLeggings((Leggings *) _inventory[index].itemPtr);

    _inventory[index].itemPtr = nullptr;
    _inventory[index].isOccupied = false;
}

void Player::unequipHelmet()
{
    if (!_armor->isHelmetEquipped()) { throw SlotEmptyException(); }

    if (_itemCount >= _inventorySize) {
        throw InventoryFullException();
    }

    unsigned short int emptySlotIndex = getFirstFreeSlot();

    _inventory[emptySlotIndex].itemPtr = (Item *) _armor->unequipHelmet();
    _inventory[emptySlotIndex].isOccupied = true;

}

void Player::unequipChestplate()
{
    if (!_armor->isChestplateEquipped()) { throw SlotEmptyException(); }

    if (_itemCount >= _inventorySize) {
        throw InventoryFullException();
    }

    unsigned short int emptySlotIndex = getFirstFreeSlot();

    _inventory[emptySlotIndex].itemPtr = (Item *) _armor->unequipChestplate();
    _inventory[emptySlotIndex].isOccupied = true;
}

void Player::unequipLeggings()
{
    if (!_armor->isLeggingsEquipped()) { throw SlotEmptyException(); }

    if (_itemCount >= _inventorySize) {
        throw InventoryFullException();
    }

    unsigned short int emptySlotIndex = getFirstFreeSlot();

    _inventory[emptySlotIndex].itemPtr = (Item *) _armor->unequipLeggings();
    _inventory[emptySlotIndex].isOccupied = true;
}
