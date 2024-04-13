//
// Created by WolfPlay on 4/10/2024.
//

#ifndef POLYMORPHISM_PLAYER_H
#define POLYMORPHISM_PLAYER_H

#include <vector>
#include <string>

#include "Item.class/item.h"
#include "Weapon.abstract/Weapon.h"

class Player {
    const std::string _name;
    float _health;
    const float _maxHealth;
    float _armor;
    const int _maxItemInventorySize;
    const int _maxWeaponInventorySize ;

    std::vector<Item*> _itemInventory;
    std::vector<Weapon*> _weaponInventory;

    Item* _equippedItem{};
    Weapon* _equippedWeapon{};

public:
    Player(std::string name, float health, float armor, int maxItemInventorySize, int maxWeaponInventorySize);
    ~Player();

    std::string getName();
    [[nodiscard]] float getHealth() const;
    [[nodiscard]] float getMaxHealth() const;
    [[nodiscard]] float getArmor() const;

    void addItemToInventory(Item* item);
    void addWeaponToInventory(Weapon* weapon);

    void removeItemFromInventory(int index);
    void removeWeaponFromInventory(int index);

    int getItemCount();
    int getWeaponCount();

    Item* getItem(int index);
    Weapon* getWeapon(int index);

    void equipItem(int index);
    void equipWeapon(int index);

    Item* getEquippedItem();
    Weapon* getEquippedWeapon();
};


#endif //POLYMORPHISM_PLAYER_H
