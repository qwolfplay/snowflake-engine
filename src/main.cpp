#include <iostream>

#include "Player.class/Player.h"
#include "Gui.class/Gui.h"

int main()
{
    Player player("Player", 50, 10, 27);

    Gui::mainMenu(&player);

    return 0;
}
