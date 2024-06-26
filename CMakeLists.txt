cmake_minimum_required(VERSION 3.26)
project(snowflake)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(include/raylib)

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
        src/Armor.abstract/Armor.cpp
        src/Armor.abstract/Armor.h
        src/Armor.abstract/Chestplate.class/Chestplate.cpp
        src/Armor.abstract/Chestplate.class/Chestplate.h
        src/Armor.abstract/Helmet.class/Helmet.cpp
        src/Armor.abstract/Helmet.class/Helmet.h
        src/Armor.abstract/Leggings.class/Leggings.cpp
        src/Armor.abstract/Leggings.class/Leggings.h
        src/Renderer.class/Renderer.cpp
        src/Renderer.class/Renderer.h
)

add_executable(snowflake
        src/main.cpp
        ${SOURCE_FILES}
)

target_include_directories(snowflake PUBLIC src)
target_include_directories(snowflake PRIVATE include/raylib/src)

target_link_libraries(snowflake PUBLIC raylib)
