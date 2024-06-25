//
// Created by WolfPlay on 6/25/2024.
//

#ifndef SNOWFLAKE_EQUIP_H
#define SNOWFLAKE_EQUIP_H

#include "../PlayerAction.h"

class Equip : public PlayerAction
{
    unsigned short _index;
public:
    Equip(Player *player, unsigned short length, unsigned short index);

    ~Equip() override;

    void perform() override;
};


#endif //SNOWFLAKE_EQUIP_H
