//
// Created by WolfPlay on 6/25/2024.
//

#include "Equip.h"

Equip::Equip(Player *player, unsigned short length, unsigned short index) :
_index(index)
{
    _player = player;
    _lengthInTicks = length;
}

Equip::~Equip() = default;

void Equip::perform()
{
    try {
        _player->unequipWeapon();
    } catch(std::exception &e) {};

    _player->equipWeapon(_index);
}
