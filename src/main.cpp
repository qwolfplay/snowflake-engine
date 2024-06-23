#include <iostream>
#include "raylib.h"

#include "Player.class/Player.h"
#include "Gui.class/Gui.h"

#include "Weapon.abstract/Weapon.h"
#include "Weapon.abstract/Sword.class/Sword.h"
#include "Armor.abstract/Armor.h"
#include "Armor.abstract/Helmet.class/Helmet.h"
#include "Armor.abstract/Chestplate.class/Chestplate.h"
#include "Armor.abstract/Leggings.class/Leggings.h"
#include "Window.class/Window.h"
#include "Sprite.class/Sprite.h"

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
    Window window(720,1280,(char*) "Title", nullptr);
    Player player("Player", 50, 27);



    std::cout << "Max HP: " << player.getMaxHealth() << std::endl;

    player.addItemToInventory(new Sword("Sword", "A sword", 10, Item::type::WEAPON, Item::rarity::COMMON, 10, 25, 5));

    // TODO: test new armor functionality
    player.addItemToInventory(new Helmet("Helmet", "A helmet", 10, Item::rarity::COMMON, 10, 25));
    player.addItemToInventory(new Chestplate("Chestplate", "A chestplate", 10, Item::rarity::COMMON, 10, 25));
    player.addItemToInventory(new Leggings("Leggings", "A leggings", 10, Item::rarity::COMMON, 10, 25));

    for (int i = 0; i < player._inventorySize; i++) {
        try {
            std::string name = player.getItemPtr(i)->getName();
            std::cout << "Index: " << i << " | Item: " << name << std::endl;
        } catch (std::exception &e) {
            std::cout << "Index: " << i << " | Exception: " << e.what() << std::endl;
        }
    }

    // TODO: More testing of new armor system

    std::cout << "DEF: " << player.getEffectiveDefence() << " | RES: " << player.getEffectiveResistance() << std::endl;

    player.equipHelmet(1);
    player.equipChestplate(2);
    player.equipLeggings(3);

    std::cout << "DEF: " << player.getEffectiveDefence() << " | RES: " << player.getEffectiveResistance() << std::endl;

    std::cout << "\nHelmet:\n";
    describeArmor(player.getHelmetPtr());

    std::cout << "\nChestplate:\n";
    describeArmor(player.getChestplatePtr());

    std::cout << "\nLeggings: ";
    describeArmor(player.getLeggingsPtr());

    for (int i = 0; i < player._inventorySize; i++) {
        try {
            std::string name = player.getItemPtr(i)->getName();
            std::cout << "Index: " << i << " | Item: " << name << std::endl;
        } catch (std::exception &e) {
        }
    }

    std::cout << std::endl;

    player.removeItemFromInventory(0);

    player.unequipHelmet();
    player.unequipChestplate();
    player.unequipLeggings();

    for (int i = 0; i < player._inventorySize; i++) {
        try {
            std::string name = player.getItemPtr(i)->getName();
            std::cout << "Index: " << i << " | Item: " << name << std::endl;
        } catch (std::exception &e) {
        }
    }

    Color color = GetColor(000000);
    Sprite enemy("assets/textures/sans.png");
    Sprite playerSprite("assets/textures/Frisk_1.png");

    playerSprite.changeTexture("assets/textures/Frisk_2.png");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        enemy.DrawSprite(500,0,WHITE);
        playerSprite.DrawSprite(0,0,WHITE);
        EndDrawing();
    }

    return 0;
}
