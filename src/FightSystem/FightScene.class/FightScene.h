//
// Created by WolfPlay on 4/29/2024.
//

#ifndef RPG_FIGHTSCENE_H
#define RPG_FIGHTSCENE_H

#include <vector>

#include "Player.class/Player.h"
#include "Enemy.class/Enemy.h"

enum PossiblePlayerActions
{
    ATTACK,
    USE,
    EQUIP,
    UNEQUIP,
    WAIT
};

// To future me:
// good luck with debugging this code UwU
// your sanity will probably be at the worst state possible with the way im implementing ticks, actions and events 💀

class FightScene
{
    typedef struct
    {
        Player *playerPtr;
        unsigned short int actionDuration;
    };
    typedef struct
    {
        PossiblePlayerActions action;
        unsigned short int targetIndex;
    } PlayerAction;

    Player *_player;
    Enemy **_enemies;

    PlayerAction _selectedPlayerAction;

    bool _endOfMove{};

    unsigned long long int _passedTicks;

    void performPlayerAction(PlayerAction action);

public:
    FightScene(Player *player, Enemy *enemies);

    ~FightScene();

    bool isAwaitingChoice();

    void selectAction(PossiblePlayerActions action, unsigned short int targetIndex);

    void selectAction(PossiblePlayerActions action, unsigned short int targetIndex, void *additionalData);

    void update();
};


#endif //RPG_FIGHTSCENE_H
