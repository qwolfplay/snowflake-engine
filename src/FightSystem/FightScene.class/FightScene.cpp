//
// Created by WolfPlay on 4/29/2024.
//

#include "FightScene.h"

FightScene::FightScene(Player *player, std::vector<Enemy> enemies) : _player(player), _enemies(std::move(enemies)) {}

Player *FightScene::getPlayerPtr()
{
    return _player;
}

std::vector<Enemy> *FightScene::getEnemiesPtr()
{
    return &_enemies;
}
