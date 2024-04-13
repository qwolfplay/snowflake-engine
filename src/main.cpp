#include <iostream>

#include "Player.class/Player.h"
#include "Weapon.abstract/Weapon.h"
#include "Weapon.abstract/Sword.class/Sword.h"
#include "Weapon.abstract/Bow.class/Bow.h"
#include "Gui.class/Gui.h"

void test(Weapon *w) {
    std::cout << " | Name: " << w->getName()
              << " | Desc: " << w->getDescription()
              << " | Price: " << w->getPrice()
              << " | Rarity: " << Item::to_string(w->getRarity())
              << std::endl
              << "Attack: " << w->getDamage()
              << " | AP: " << w->getArmorPenetration()
              << " | ATKSPD: " << w->getAttackSpeed() << std::endl;
}

int main() {
    Sword sword("test", ":3", 25.6, Item::COMMON, 20, 15, 3);
    Bow bow("test2", "^w^", 35.1, Item::RARE, 8, 5, 1);

    Player player("Avalanche :3", 50, 10, 27, 9);

    player.addWeaponToInventory(&sword);
    player.addWeaponToInventory(&bow);

    for (int i = 0; i < player.getWeaponCount(); i++) {
        test(player.getWeapon(i));
    }

    std::cout << std::endl
              << "Player: " << player.getName()
              << " | HP: " << player.getHealth()
              << " | MAXHP: " << player.getMaxHealth()
              << " | DEF: " << player.getArmor()
              << std::endl;

    Item *item = player.getWeapon(0);
    std::cout << "\n" << item->getName() << " | " << item->getDescription() << "\n";

    Gui::mainMenu(&player);

    return 0;
}
