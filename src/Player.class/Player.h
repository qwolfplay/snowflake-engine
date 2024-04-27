//
// Created by WolfPlay on 4/10/2024.
//

#ifndef POLYMORPHISM_PLAYER_H
#define POLYMORPHISM_PLAYER_H

#include <vector>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "Item.class/item.h"
#include "Weapon.abstract/Weapon.h"
#include "ArmorSet.class/ArmorSet.h"
#include "Armor.abstract/Helmet.class/Helmet.h"
#include "Armor.abstract/Chestplate.class/Chestplate.h"
#include "Armor.abstract/Leggings.class/Leggings.h"

class Player
{
public:
    typedef struct
    {
        Item *itemPtr;
        bool isOccupied;
    } InventorySlot;

private:
    const std::string _name;
    float _health;
    const float _maxHealth;

    unsigned short int _itemCount = 0;

    InventorySlot *_inventory;
    ArmorSet *_armor;
    Weapon *_equippedWeapon{};

public:
    const unsigned short int _inventorySize;

    Player(std::string name, float health, unsigned short int maxInventorySize);

    ~Player();

    std::string getName();

    [[nodiscard]] float getHealth() const;

    [[nodiscard]] float getMaxHealth() const;

    void addItemToInventory(Item *item);

    void removeItemFromInventory(unsigned short int index);

    float getEffectiveDefence();

    float getEffectiveResistance();

    [[nodiscard]] int getItemCount() const;

    [[nodiscard]] std::vector<unsigned short int> getFreeSlots() const;

    Item *getItemPtr(unsigned short int index);

    void equipWeapon(unsigned short int index);

    void equipHelmet(unsigned short int index);

    void equipChestplate(unsigned short int index);

    void equipLeggings(unsigned short int index);

    [[nodiscard]] Helmet *getHelmetPtr() const;

    [[nodiscard]] Chestplate *getChestplatePtr() const;

    [[nodiscard]] Leggings *getLeggingsPtr() const;

    void unequipHelmet();

    void unequipChestplate();

    void unequipLeggings();

    Weapon *getEquippedWeapon();
};


#endif //POLYMORPHISM_PLAYER_H
