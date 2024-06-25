cmake_minimum_required(VERSION 3.26)
project(snowflake)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(include/cpp-core)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++")
endif()

set(SOURCE_FILES
        src/Item.class/Food.class/Food.cpp
        src/Item.class/Item.cpp
        src/Enemy.class/Enemy.cpp
        src/Armor.abstract/Armor.cpp
        src/Armor.abstract/Chestplate.class/Chestplate.cpp
        src/Armor.abstract/Helmet.class/Helmet.cpp
        src/Armor.abstract/Leggings.class/Leggings.cpp
        src/ArmorSet.class/ArmorSet.cpp
        src/Weapon.abstract/Weapon.cpp
        src/Weapon.abstract/Bow.class/Bow.cpp
        src/Weapon.abstract/Sword.class/Sword.cpp
        src/Weapon.abstract/Wand.class/Wand.cpp
        src/Player.class/Player.cpp
        src/Gui.class/Gui.cpp
        src/FightSystem/FightScene.class/FightScene.cpp
        src/FightSystem/FightScene.class/FightScene.h
        src/FightSystem/Event.class/Event.cpp
        src/FightSystem/Event.class/Event.h
        src/FightSystem/FightScene.class/PlayerActions/Attack.cpp
        src/FightSystem/FightScene.class/PlayerActions/Attack.h
)

add_executable(snowflake
        src/main.cpp
        ${SOURCE_FILES}
)

target_include_directories(snowflake PUBLIC src)
target_include_directories(snowflake PRIVATE include/cpp-core/src)

target_link_libraries(snowflake PRIVATE core)