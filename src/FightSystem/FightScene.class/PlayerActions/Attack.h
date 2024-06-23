//
// Created by WolfPlay on 6/23/2024.
//

#ifndef RPG_ATTACK_H
#define RPG_ATTACK_H

#include "FightSystem/FightScene.class/PlayerAction.h"
#include "Enemy.class/Enemy.h"

class Attack : public PlayerAction
{
    Enemy *_target;

public:
    Attack(unsigned short length, Player *player, Enemy *target);

    ~Attack() override;

    void perform() override;

    Player *getPlayerPtr();

    Enemy *getTargetPtr();
};

#endif //RPG_ATTACK_H
