#include <iostream>

#include "Player.class/Player.h"
#include "Gui.class/Gui.h"

#include "Weapon.abstract/Weapon.h"
#include "Weapon.abstract/Sword.class/Sword.h"
#include "Armor.abstract/Helmet.class/Helmet.h"
#include "Armor.abstract/Chestplate.class/Chestplate.h"
#include "Armor.abstract/Leggings.class/Leggings.h"
#include "Weapon.abstract/Sword.class/Sword.h"
#include "Item.class/Consumable.abstract/HealingConsumable.class/HealingConsumable.h"

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

void describeItem(Consumable *item){
    printf("Name: %s\n"
           "Desc: %s\n"
           "Price: %f\n"
           "Rarity: %d\n",
           item->getName().c_str(),
           item->getDescription().c_str(),
           item->getPrice(),
           item->getRarity());
}

void describePlayer(Player &player) {
    printf("Name: %s | HP: %f | Max HP: %f | Inv Size: %i | DEF: %f | Damage Red: %f\n",
           player.getName().c_str(),
           player.getHealth(),
           player.getMaxHealth(),
           player._inventorySize,
           player.getArmorSetPtr()->getEffectiveDefence(),
           player.getArmorSetPtr()->getDamageReductionMultiplier()
           );
}

void describeEnemy(Enemy *enemy) {
    printf("HP: %f | Max HP: %i | DMG Red: %f\n",
           enemy->getHealth(),
           enemy->getMaxHealth(),
           enemy->getArmorPtr()->getDamageReductionMultiplier()
       );
}

int main()
{
    Player player("Player", 50, 27);

    player.addItemToInventory(new Helmet("Helmet", "A helmet", 25.6, Item::Rarity::COMMON, 5.0, 3.0));
    player.addItemToInventory(new Chestplate("Chestplate", "A chestplate", 50.0, Item::Rarity::RARE, 10.0, 5.0));
    player.addItemToInventory(new Leggings("Leggings", "A pair of leggings", 35.0, Item::Rarity::UNCOMMON, 7.0, 4.0));
    player.addItemToInventory(new Sword("Sword", ":3", 2137.0f, Item::Rarity::LEGENDARY, 25, 14, 9));
    player.addItemToInventory(new HealingConsumable("Apple", "UwU", 0, Item::Rarity::COMMON, 15));

    for (unsigned short i = 0; i < player._inventorySize; i++) {
        try {
            switch (player.getItemPtr(i)->getType()) {
                case Item::ItemType::WEAPON:
                    describeItem((Weapon *) (player.getItemPtr(i)));
                    break;
                case Item::ItemType::ARMOR:
                    describeItem((Armor *) (player.getItemPtr(i)));
                    break;
                case Item::ItemType::CONSUMABLE:
                    describeItem((Consumable *) (player.getItemPtr(i)));
                default:
                    break;
            }
            printf("Index: %u\n\n", i);
        } catch (std::exception &e) {
            printf("Slot %u is empty\n", i);
        }
    }

    player.equipHelmet(0);
    player.equipChestplate(1);
    player.equipLeggings(2);
    player.equipWeapon(3);

//    printf("DEF: %f\n", player.getArmorSetPtr()->getEffectiveDefence());
//    printf("Dmg Reduction: %f%%\n", (player.getArmorSetPtr()->getDamageReductionMultiplier()) * 100.0f);
//
//    printf("Damage: %f\n", player.getEquippedWeaponPtr()->getDamage());
//    printf("Damage Subtracted: %f\n",
//           player.getArmorSetPtr()->getDamageReduction(
//                   player.getEquippedWeaponPtr()->getDamage()
//           )
//    );

    describePlayer(player);

    player.takeRawDamage(49);
    describePlayer(player);
    auto *testPtr = (HealingConsumable *)player.getItemPtr(4);
    testPtr->use(&player);
    describePlayer(player);

    return 0;
}
