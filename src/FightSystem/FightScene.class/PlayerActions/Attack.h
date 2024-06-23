//
// Created by WolfPlay on 6/23/2024.
//

#ifndef RPG_ATTACK_H
#define RPG_ATTACK_H

#include "FightSystem/FightScene.class/PlayerAction.h"
#include "Enemy.class/Enemy.h"
#include "FightSystem/FightScene.class/FightScene.h"

class Attack : private PlayerAction
{
    Enemy *_target;

public:
    Attack(unsigned short length, Player *player, Enemy *target);

    void perform() override;
};


#endif //RPG_ATTACK_H
