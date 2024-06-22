//
// Created by WolfPlay on 4/29/2024.
//

#include "FightScene.h"

FightScene::FightScene(Player *player, EnemiesCollection enemiesCollection) :
    _player(player),
    _enemyCount(enemiesCollection.size),
    _enemies(enemiesCollection.enemies) {}

Player *FightScene::getPlayerPtr()
{
    return _player;
}
