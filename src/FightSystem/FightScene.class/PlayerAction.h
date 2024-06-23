//
// Created by WolfPlay on 6/23/2024.
//

#ifndef RPG_PLAYERACTION_H
#define RPG_PLAYERACTION_H

#include "Player.class/Player.h"

class PlayerAction
{
protected:
    Player *_player{};
    unsigned short _lengthInTicks{};

public:
    virtual void perform() = 0;
};


#endif //RPG_PLAYERACTION_H
