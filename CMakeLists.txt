cmake_minimum_required(VERSION 3.27)
project(rpg)

set(CMAKE_CXX_STANDARD 23)

set(SOURCE_FILES
        src/Weapon.abstract/Bow.class/Bow.cpp
        src/Item.class/Food.class/Food.cpp
        src/Item.class/Item.cpp
        src/Weapon.abstract/Sword.class/Sword.cpp
        src/Weapon.abstract/Wand.class/Wand.cpp
        src/Weapon.abstract/Weapon.cpp
        src/Enemy.class/Enemy.cpp
        src/Player.class/Player.cpp
        src/Gui.class/Gui.cpp
)

add_executable(rpg
        src/main.cpp
        ${SOURCE_FILES}
)

target_include_directories(rpg PUBLIC src)

