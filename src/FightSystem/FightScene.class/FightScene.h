//
// Created by WolfPlay on 4/29/2024.
//

#ifndef RPG_FIGHTSCENE_H
#define RPG_FIGHTSCENE_H

#include <vector>

#include "Player.class/Player.h"
#include "Enemy.class/Enemy.h"
#include "PlayerAction.h"
#include "PlayerActions/Attack.h"


// To future me:
// good luck with debugging this code UwU
// your sanity will probably be at the worst state possible with the way im implementing ticks, actions and events 💀

class FightScene
{
public:
    typedef struct {
        unsigned short size;
        Enemy** enemies;
    } EnemiesCollection;

private:
    Player *_player;
    std::vector<Enemy> _enemies;

public:
    FightScene(Player *player, EnemiesCollection enemiesCollection);

    ~FightScene() = default;

    Player* getPlayerPtr();

    Enemy* getEnemyPtr(unsigned int index);

    unsigned short getEnemyCount();

    void performPlayerAction(PlayerAction &action);

    Attack createAttackAction(unsigned short enemyIndex);

    bool shouldFightEnd();

    void fightLoop();
};


#endif //RPG_FIGHTSCENE_H
