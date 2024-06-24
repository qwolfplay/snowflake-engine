//
// Created by WolfPlay on 4/29/2024.
//

#include "FightScene.h"

#include <chrono>
#include <thread>

#include "core.h"

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
    return {30, _player, getEnemyPtr(enemyIndex)};
}

Attack *FightScene::createAttackActionPtr(unsigned short enemyIndex)
{
    return new Attack(30, _player, getEnemyPtr(enemyIndex));
}

bool FightScene::shouldFightEnd()
{
    if (_player->isDead())  { return true; }
    for (const Enemy &enemy : _enemies) {
        if (!enemy.isDead()) { return false; }
    }

    return true;
}

// so the fight should update 64 times a second (so 64 tick per second)
// this means that we need to check if player should take an action and if yes we need to wait until this action gets performed,
// and then we need to wait until the action and or enemy action ended so that next action can be selected and performed

void FightScene::fightLoop()
{

    PlayerAction *selectedPlayerAction;
    unsigned short ticksLeftToCompletePlayerAction = 0;
    auto *ticksLeftToCompleteEnemyAction = new unsigned short[_enemies.size()];
    core::fillArrayWithZeros(ticksLeftToCompleteEnemyAction, _enemies.size(), sizeof(unsigned short));

    unsigned short tickCount = 0;

    const std::chrono::milliseconds frameDuration(1000 / 60);
    do {
        auto start = std::chrono::high_resolution_clock::now();

        if (ticksLeftToCompletePlayerAction <= 0) {
            unsigned short a = 0;
            printf("\n");
            for (Enemy &j : _enemies) {
                printf("Enemy %i | HP: %f | Dead: %s\n", a, j.getHealth(), j.isDead() ? "true" : "false");
                a++;
            }
            printf("Select enemy to attack: ");
            unsigned short enemyIndex;
            scanf("%hi", &enemyIndex);
            selectedPlayerAction = createAttackActionPtr(enemyIndex);
            printf("\nCreated new action\n");
            ticksLeftToCompletePlayerAction = selectedPlayerAction->getLength();
            selectedPlayerAction->perform();
            delete selectedPlayerAction;
        }

        for (int i = 0; i < _enemies.size(); i++) {
            if (ticksLeftToCompleteEnemyAction[i] <= 0) {

            }
        }
        
        tickCount++;
        ticksLeftToCompletePlayerAction--;

        auto execTime = std::chrono::high_resolution_clock::now() - start;
        printf("\rTick: %lli | Tick time: %lli | Ticks left: %lli                ", tickCount, std::chrono::duration_cast<std::chrono::microseconds>(execTime).count(), ticksLeftToCompletePlayerAction);
        if (execTime < frameDuration) {
            std::this_thread::sleep_for(frameDuration - execTime);
        }

    } while (!shouldFightEnd());
}
