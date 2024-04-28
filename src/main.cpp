#include <iostream>

#include "Player.class/Player.h"
#include "Gui.class/Gui.h"

#include "Weapon.abstract/Weapon.h"
#include "Weapon.abstract/Sword.class/Sword.h"
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
//    std::cout << std::endl;
}

int main()
{
    Player player("Player", 50, 27);

    player.addItemToInventory(new Helmet("Helmet", "A helmet", 25.6, Item::rarity::COMMON, 5.0, 3.0));
    player.addItemToInventory(new Chestplate("Chestplate", "A chestplate", 50.0, Item::rarity::RARE, 10.0, 5.0));
    player.addItemToInventory(new Leggings("Leggings", "A pair of leggings", 35.0, Item::rarity::UNCOMMON, 7.0, 4.0));

    for (unsigned short i = 0; i < player._inventorySize; i++) {
        try {
            describeArmor((Armor *) (player.getItemPtr(i)));
            printf("Index: %u\n\n", i);
        } catch (std::exception &e) {
            continue;
        }
    }

    player.equipHelmet(0);
    player.equipChestplate(1);
    player.equipLeggings(2);

    printf("DEF: %f\n", player.getArmorSetPtr()->getEffectiveDefence());
    printf("Dmg Reduction: %f%%\n", (player.getArmorSetPtr()->getDamageReductionMultiplier()) * 100.0f);

    return 0;
}
