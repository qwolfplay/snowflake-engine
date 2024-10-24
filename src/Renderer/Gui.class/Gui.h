//
// Created by WolfPlay on 4/11/2024.
//

#ifndef SNOWFLAKE_GUI_H
#define SNOWFLAKE_GUI_H

#include "Player.class/Player.h"
#include "Weapon.abstract/Weapon.h"
#include "Enemy.class/Enemy.h"

namespace Snowflake {
class Gui {
public:
    enum menus {
        MAIN_MENU,
        SHOP_MENU,
        INVENTORY_MENU,
        ATTACK_SIMULATION,
        ATTACK_SCREEN
    };
    static void menu(menus selectedMenu, Player *player);
    static void printWeapon(Weapon *w);
    static void mainMenu(Player *player);
    static void shopMenu(Player *player);
    static void inventoryMenu(Player *player);
    static void simulationMenu(Player *player);
    static void attackScreen(Player *player, Enemy *enemy);
};
}


#endif //SNOWFLAKE_GUI_H
