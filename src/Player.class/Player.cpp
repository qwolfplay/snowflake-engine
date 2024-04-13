//
// Created by WolfPlay on 4/10/2024.
//

#include <stdexcept>
#include <string>

#include "Player.h"

Player::Player(std::string name, float health, float armor, int maxItemInventorySize, int maxWeaponInventorySize) :
    _name(std::move(name)),
    _health(health),
    _maxHealth(health),
    _armor(armor),
    _maxItemInventorySize(maxItemInventorySize),
    _maxWeaponInventorySize(maxWeaponInventorySize)
{};

Player::~Player() = default;

std::string Player::getName() {
    return _name;
}

float Player::getHealth() const {
    return _health;
}

float Player::getMaxHealth() const {
    return _maxHealth;
}

float Player::getArmor() const {
    return _armor;
}

void Player::addItemToInventory(Item* item) {
    if (_itemInventory.size() < _maxItemInventorySize) {
        _itemInventory.push_back(item);
    } else {
        throw std::exception("Inventory is full");
    }
}

void Player::addWeaponToInventory(Weapon* weapon) {
    if (_weaponInventory.size() < _maxWeaponInventorySize) {
        _weaponInventory.push_back(weapon);
    } else {
        throw std::exception("Inventory is full");
    }
}

void Player::removeItemFromInventory(int index) {
    _itemInventory.erase(_itemInventory.begin() + index);
}

void Player::removeWeaponFromInventory(int index) {
    _weaponInventory.erase(_weaponInventory.begin() + index);
}

int Player::getItemCount() {
    return _itemInventory.size();
}

int Player::getWeaponCount() {
    return _weaponInventory.size();
}

Item* Player::getItem(int index) {
    return _itemInventory[index];
}

Weapon* Player::getWeapon(int index) {
    return _weaponInventory[index];
}


void Player::equipItem(int index) {
    _equippedItem = _itemInventory[index];
}

void Player::equipWeapon(int index) {
    _equippedWeapon = _weaponInventory[index];
}

Item* Player::getEquippedItem() {
    return _equippedItem;
}

Weapon* Player::getEquippedWeapon() {
    return _equippedWeapon;
}

