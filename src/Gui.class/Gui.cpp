//
// Created by WolfPlay on 4/11/2024.
//

#include "Gui.h"

#include <iostream>
#include <stdexcept>

#include "Player.class/Player.h"
#include "Weapon.abstract/Sword.class/Sword.h"
#include "Weapon.abstract/Bow.class/Bow.h"
#include "Weapon.abstract/Wand.class/Wand.h"

void Gui::menu(Gui::menus selectedMenu, Player *player) {
    switch (selectedMenu) {
        case MAIN_MENU:
            mainMenu(player);
            break;
        case SHOP_MENU:
            shopMenu(player);
            break;
        case INVENTORY_MENU:
            inventoryMenu(player);
            break;
        case ATTACK_SIMULATION:
            simulationMenu(player);
            break;
        default:
            if (selectedMenu == 9) { return; }
            else {
                throw std::invalid_argument("Zły wybór");
            }
    }
}

void Gui::printWeapon(Weapon *w) {
    std::cout << "Name: " << w->getName()
              << " | Desc: " << w->getDescription()
              << " | Price: " << w->getPrice()
              << " | Rarity: " << Item::to_string(w->getRarity())
              << std::endl
              << "Attack: " << w->getDamage()
              << " | AP: " << w->getArmorPenetration()
              << " | ATKSPD: " << w->getAttackSpeed() << std::endl;
}

void Gui::mainMenu(Player *player) {
    std::cout << "Polimorfizm" << "\n\n"
              << "1. Sklep" << "\n"
              << "2. Ekwipunek" << "\n"
              << "3. Symulacja ataku" << "\n"
              << "\n9. Wyjście" << "\n\n";

    std::cout << "Wybierz opcję: ";
    int option;
    std::cin >> option;
    try {
        menu(static_cast<menus>(option), player);
    } catch (std::invalid_argument &e) {
        mainMenu(player);
    }
}

void Gui::shopMenu(Player *player) {
    std::cout << "Sklep" << "\n\n"
              << "1. Miecz"<< "\n"
              << "2. Łuk" << "\n"
              << "3. Różdżka" << "\n\n";

    std::cout << "Wybierz opcję: ";
    int option;
    std::cin >> option;
    try {
        switch (option) {
            case 1:
                player->addWeaponToInventory(new Sword("Miecz", ":3", 25.6, Item::COMMON, 20, 15, 3));
                break;
            case 2:
                player->addWeaponToInventory(new Bow("Łuk", "UwU", 35.1, Item::RARE, 8, 5, 1));
                break;
            case 3:
                player->addWeaponToInventory(new Wand("Różdżka", "OwO", 45.3, Item::EPIC, 15, 10, 2));
                break;
            default:
                throw std::invalid_argument("Zły wybór");
        }

    } catch (std::invalid_argument &e) {
        menu(SHOP_MENU, player);
    }
    menu(MAIN_MENU, player);
}

void Gui::inventoryMenu(Player *player) {
    std::cout << "Ekwipunek" << "\n\n";

    for (int i = 0; i < player->getWeaponCount(); i++) {
        printWeapon(player->getWeapon(i));
        std::cout << "\n";
    }

    menu(MAIN_MENU, player);
}

void Gui::attackScreen(Player *player, Enemy *enemy) {
    std::cout << "\n" << player->getName() << ": " << player->getHealth() << " | " << player->getArmor() << "\n";
    std::cout << "Przeciwnik: " << enemy->getHealth() << " | " << enemy->getArmor() << "\n\n";

    std::cout << "1. Atak" << "\n"
              << "2. Powrót" << "\n\n";
    std::cout << "Wybierz opcję: ";
    int option;
    std::cin >> option;


    switch (option) {
        case 1:
            player->getEquippedWeapon()->attack(enemy);
            std::cout << "Zadano obrażenia" << "\n";
            attackScreen(player, enemy);
            break;
        case 2:
            mainMenu(player);
            break;
        default:
            attackScreen(player, enemy);
    }

}

void Gui::simulationMenu(Player *player) {
    std::cout << "Symulacja ataku" << "\n\n";

    for (int i = 0; i < player->getWeaponCount(); i++) {
        printWeapon(player->getWeapon(i));
        std::cout << "\n";
    }

    std::cout << "Wybierz broń: ";
    int option;
    std::cin >> option;
    player->equipWeapon(option);

    std::cout << "Utwórz przeciwnika (hp, armor): ";
    float enemyHealth, enemyArmor;
    std::cin >> enemyHealth >> enemyArmor;

    Gui::attackScreen(player, new Enemy(enemyHealth, enemyArmor));
}

