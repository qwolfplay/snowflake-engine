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

// so the fight should update 64 times a second (so 64 tick per second)
// this means that we need to check if player should take an action and if yes we need to wait until this action gets performed,
// and then we need to wait until the action and or enemy action ended so that next action can be selected and performed

class FightScene
{
public:
    typedef struct {
        unsigned short size;
        Enemy** enemies;
    } EnemiesCollection;

private:
    Player *_player;
    std::vector<Enemy> enemies;

public:
    FightScene(Player *player, EnemiesCollection enemiesCollection);

    ~FightScene() = default;

    Player* getPlayerPtr();

    Enemy* getEnemyPtr(unsigned int index);

    unsigned short getEnemyCount();

    void performPlayerAction(PlayerAction &action);

    Attack createAttackAction(unsigned short enemyIndex);
};


#endif //RPG_FIGHTSCENE_H
