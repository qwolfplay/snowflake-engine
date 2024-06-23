//
// Created by WolfPlay on 4/29/2024.
//

#include "FightScene.h"

#include <chrono>
#include <thread>

#include "PlayerAction.h"
#include "PlayerActions/Attack.h"

FightScene::FightScene(Player *player, EnemiesCollection enemiesCollection) :
_player(player) {
    _enemies.reserve(enemiesCollection.size); // THIS LINE WAS THE SOLUTION TO A BUG THAT I BATTLE FOR OVER 4 FLUFFING HOURS 💀
    for(unsigned short i = 0; i < enemiesCollection.size; i++) {
        _enemies.emplace_back(enemiesCollection.enemies[i]->getMaxHealth());
    }
}

Player *FightScene::getPlayerPtr()
{
    return _player;
}

Enemy *FightScene::getEnemyPtr(unsigned int index)
{
    return &_enemies[index];
}

unsigned short FightScene::getEnemyCount()
{
    return _enemies.size();
}

void FightScene::performPlayerAction(PlayerAction &action)
{
    try {
        action.perform();
    } catch (std::exception &e) {
        printf("Error");
    }
}

Attack FightScene::createAttackAction(unsigned short enemyIndex)
{
    return {26, _player, getEnemyPtr(enemyIndex)};
}

bool FightScene::shouldFightEnd()
{
    if (_player->isDead())  { return true; }
    if (_enemies.empty())   { return true; }

    return false;
}

// so the fight should update 64 times a second (so 64 tick per second)
// this means that we need to check if player should take an action and if yes we need to wait until this action gets performed,
// and then we need to wait until the action and or enemy action ended so that next action can be selected and performed

void FightScene::fightLoop()
{

    PlayerAction *selectedPlayerAction{};
    unsigned short ticksLeftToCompletePlayerAction = 0;
    bool isPlayerActionDone;

    unsigned short i = 0;

    const std::chrono::milliseconds frameDuration(1000 / 64);
    while (!shouldFightEnd()) {
        auto start = std::chrono::high_resolution_clock::now();



        auto execTime = std::chrono::high_resolution_clock::now() - start;
        if (execTime < frameDuration) {
            std::this_thread::sleep_for(frameDuration - execTime);
        }
    }
}


