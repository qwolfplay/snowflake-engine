#include <iostream>

#include "Player.class/Player.h"
#include "Weapon.abstract/Weapon.h"
#include "Weapon.abstract/Sword.class/Sword.h"
#include "Weapon.abstract/Bow.class/Bow.h"
#include "Gui.class/Gui.h"

int main()
{
    Player player("Player", 50, 10, 27);

    Gui::mainMenu(&player);

    return 0;
}
