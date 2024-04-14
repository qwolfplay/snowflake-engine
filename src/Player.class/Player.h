//
// Created by WolfPlay on 4/10/2024.
//

#ifndef POLYMORPHISM_PLAYER_H
#define POLYMORPHISM_PLAYER_H

#include <vector>
#include <string>
#include <exception>
#include <stdexcept>

#include "Item.class/item.h"
#include "Weapon.abstract/Weapon.h"

class Player
{
    const std::string _name;
    float _health;
    const float _maxHealth;
    float _armor;
    const int _maxItemInventorySize;

    unsigned short int _itemCount = 0;
    typedef struct
    {
        Item *itemPtr;
        bool isOccupied;
    } InventorySlot;

    InventorySlot *_inventory;
    Weapon *_equippedWeapon{};

public:
    class InventoryFullException : public std::exception
    {
        std::string _message = "Inventory is full";
    public:
        [[nodiscard]] const char *what() const noexcept override
        {
            return _message.c_str();
        }
    };

    class SlotEmptyException : public std::exception
    {
        std::string _message = "Slot is empty";
    public:
        [[nodiscard]] const char *what() const noexcept override
        {
            return _message.c_str();
        }
    };

    class WrongItemTypeException : public std::exception
    {
        std::string _message = "Item is not a weapon";
    public:
        [[nodiscard]] const char *what() const noexcept override
        {
            return _message.c_str();
        }
    };

    Player(std::string name, float health, float armor, unsigned short int maxInventorySize);

    ~Player();

    std::string getName();

    [[nodiscard]] float getHealth() const;

    [[nodiscard]] float getMaxHealth() const;

    [[nodiscard]] float getArmor() const;

    void addItemToInventory(Item *item);

    void removeItemFromInventory(unsigned short int index);

    int getItemCount();

    Item *getItem(int index);

    void equipWeapon(int index);

    Weapon *getEquippedWeapon();
};


#endif //POLYMORPHISM_PLAYER_H
