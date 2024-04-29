//
// Created by WolfPlay on 4/29/2024.
//

#include "FightScene.h"

bool FightScene::isAwaitingChoice()
{
    return _endOfMove;
}

void FightScene::performPlayerAction(FightScene::PlayerAction action)
{
    switch (action.action) {
        case PossiblePlayerActions::ATTACK:
            _player->getEquippedWeaponPtr()->attack(_enemies[0]);
        default:
            break;
    }
}

void FightScene::selectAction(PossiblePlayerActions action, unsigned short targetIndex)
{
    _selectedPlayerAction = PlayerAction(action, targetIndex);
}

void FightScene::selectAction(PossiblePlayerActions action, unsigned short targetIndex, void *additionalData)
{
    // im gonna leave it as is for now cause i dont really have an idea how to implement additional data for now=
}

void FightScene::update()
{
    try {
        performPlayerAction(_selectedPlayerAction);
    } catch (std::exception &e) {
        printf("ERROR: %s", e.what());
        return;
    }

    if (_endOfMove) { return; }
    else { update(); }
}