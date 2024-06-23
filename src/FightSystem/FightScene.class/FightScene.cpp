//
// Created by WolfPlay on 4/29/2024.
//

#include "FightScene.h"

#include "PlayerAction.h"

FightScene::FightScene(Player *player, EnemiesCollection enemiesCollection) :
_player(player) {
    enemies.reserve(enemiesCollection.size); // THIS LINE WAS THE SOLUTION TO A BUG THAT I BATTLE FOR OVER 4 FLUFFING HOURS 💀
    for(unsigned short i = 0; i < enemiesCollection.size; i++) {
        enemies.emplace_back(enemiesCollection.enemies[i]->getMaxHealth());
    }
}

Player *FightScene::getPlayerPtr()
{
    return _player;
}

Enemy *FightScene::getEnemyPtr(unsigned int index)
{
    return &enemies[index];
}

unsigned short FightScene::getEnemyCount()
{
    return enemies.size();
}

