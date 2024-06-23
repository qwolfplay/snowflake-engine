//
// Created by WolfPlay on 6/23/2024.
//

#include "Attack.h"

Attack::Attack(unsigned short length, Player *player, Enemy *target)
{
    _player = player;
    _target = target;
    _lengthInTicks = length;
}

void Attack::perform()
{
    printf("Performing attack action | Target: %p | Damage: %f\n", _target, _player->getEquippedWeaponPtr()->getDamage());
    _player->getEquippedWeaponPtr()->attack(_target);
}
