#include <iostream>

#include "Player.class/Player.h"
#include "Gui.class/Gui.h"

#include "Weapon.abstract/Weapon.h"
#include "Weapon.abstract/Sword.class/Sword.h"
#include "Armor.abstract/Helmet.class/Helmet.h"
#include "Armor.abstract/Chestplate.class/Chestplate.h"
#include "Armor.abstract/Leggings.class/Leggings.h"
#include "Weapon.abstract/Sword.class/Sword.h"

#include "FightSystem/FightScene.class/FightScene.h"

void describeItem(Armor *item)
{
    std::cout << "Name: " << item->getName() << std::endl;
    std::cout << "Desc: " << item->getDescription() << std::endl;
    std::cout << "Price: " << item->getPrice() << std::endl;
    std::cout << "Rarity: " << item->getRarity() << std::endl;
    std::cout << "DEF: " << item->getEffectiveDefence() << std::endl;
    std::cout << "RES: " << item->getEffectiveResistance() << std::endl;
//    std::cout << std::endl;
}

void describeItem(Weapon *item)
{
    printf("Name: %s\n"
           "Desc: %s\n"
           "Price: %f\n"
           "Rarity: %d\n"
           "DMG: %f\n"
           "AP: %f\n"
           "AS: %f\n",
           item->getName().c_str(),
           item->getDescription().c_str(),
           item->getPrice(),
           item->getRarity(),
           item->getDamage(),
           item->getArmorPenetration(),
           item->getAttackSpeed()
    );
}



int main()
{
    Player player("Player", 50, 27);

    player.addItemToInventory(new Helmet("Helmet", "A helmet", 25.6, Item::rarity::COMMON, 5.0, 3.0));
    player.addItemToInventory(new Chestplate("Chestplate", "A chestplate", 50.0, Item::rarity::RARE, 10.0, 5.0));
    player.addItemToInventory(new Leggings("Leggings", "A pair of leggings", 35.0, Item::rarity::UNCOMMON, 7.0, 4.0));
    player.addItemToInventory(new Sword("Sword", ":3", 2137.0f, Item::rarity::LEGENDARY, 25, 14, 9));

//    for (unsigned short i = 0; i < player._inventorySize; i++) {
//        try {
//            switch (player.getItemPtr(i)->getType()) {
//                case Item::type::WEAPON:
//                    describeItem((Weapon *) (player.getItemPtr(i)));
//                    break;
//                case Item::type::ARMOR:
//                    describeItem((Armor *) (player.getItemPtr(i)));
//                    break;
//                default:
//                    break;
//            }
//            printf("Index: %u\n\n", i);
//        } catch (std::exception &e) {
//            printf("Slot %u is empty\n", i);
//        }
//    }

    player.equipHelmet(0);
    player.equipChestplate(1);
    player.equipLeggings(2);
    player.equipWeapon(3);

    printf("DEF: %f\n", player.getArmorSetPtr()->getEffectiveDefence());
    printf("Dmg Reduction: %f%%\n", (player.getArmorSetPtr()->getDamageReductionMultiplier()) * 100.0f);

    printf("Damage: %f\n", player.getEquippedWeaponPtr()->getDamage());
    printf("Damage Subtracted: %f\n",
           player.getArmorSetPtr()->getDamageReduction(
                   player.getEquippedWeaponPtr()->getDamage()
           )
    );

    FightScene::EnemiesCollection collection;

    collection.size = 4;
    collection.enemies = new Enemy*[4];

    collection.enemies[0] = new Enemy(1);
    collection.enemies[1] = new Enemy(2);
    collection.enemies[2] = new Enemy(3);
    collection.enemies[3] = new Enemy(4);

    FightScene fightScene(&player, collection);

    delete collection.enemies;

    return 0;
}
