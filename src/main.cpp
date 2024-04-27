#include <iostream>

#include "Player.class/Player.h"
#include "Gui.class/Gui.h"

#include "Weapon.abstract/Weapon.h"
#include "Weapon.abstract/Sword.class/Sword.h"
#include "Armor.abstract/Armor.h"
#include "Armor.abstract/Helmet.class/Helmet.h"
#include "Armor.abstract/Chestplate.class/Chestplate.h"
#include "Armor.abstract/Leggings.class/Leggings.h"

void describeArmor(Armor *item)
{
    std::cout << "Name: " << item->getName() << std::endl;
    std::cout << "Desc: " << item->getDescription() << std::endl;
    std::cout << "Price: " << item->getPrice() << std::endl;
    std::cout << "Rarity: " << item->getRarity() << std::endl;
    std::cout << "DEF: " << item->getEffectiveDefence() << std::endl;
    std::cout << "RES: " << item->getEffectiveResistance() << std::endl;
    std::cout << std::endl;
}

int main()
{
    Player player("Player", 50, 27);

    std::cout << "Max HP: " << player.getMaxHealth() << std::endl;

    player.addItemToInventory(
            new Sword("Sword", "A sword", 10, Item::type::WEAPON, Item::rarity::COMMON, 10, 25, 5, 55, 1.65));

    for (int i = 0; i < player._inventorySize; i++) {
        try {
            std::string name = player.getItemPtr(i)->getName();
            std::cout << "Index: " << i << " | Item: " << name << std::endl;
        } catch (std::exception &e) {
        }
    }

    Gui::mainMenu(&player);

    return 0;
}
