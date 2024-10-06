cmake_minimum_required(VERSION 3.26)
project(snowflake)

set(CMAKE_CXX_STANDARD 23)

if(CMAKE_CONFIGURATION_TYPES)   # Multi-config generator
    add_definitions(-DCURRENT_BUILD_TYPE=\"$<CONFIG>\")
else()                          # Single-config generator
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_definitions(-DDEBUG_BUILD)
    elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
        add_definitions(-DRELEASE_BUILD)
    elseif(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
        add_definitions(-DRELWITHDEBINFO_BUILD)
    elseif(CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
        add_definitions(-DMINSIZEREL_BUILD)
    endif()
endif()


add_subdirectory(include/raylib)
add_subdirectory(include/spdlog)
#add_subdirectory(include/snowball-core)

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
        src/Renderer/Renderer.cpp
        src/Renderer/Renderer.h
        src/Logger.class/Logger.cpp
        src/Logger.class/Logger.h
        src/Renderer/Scene.class/Scene.cpp
        src/Renderer/Scene.class/Scene.h
        src/Renderer/UIElement.class/UIElement.cpp
        src/Renderer/UIElement.class/UIElement.h
        src/Exceptions/LoggerNotInitialized.h
)

add_executable(snowflake
        src/main.cpp
        ${SOURCE_FILES}
)

target_include_directories(snowflake PUBLIC src)
target_include_directories(snowflake PRIVATE include/raylib/src)
target_include_directories(snowflake PRIVATE include/spdlog/include)

target_link_libraries(snowflake PRIVATE raylib)
target_link_libraries(snowflake PRIVATE spdlog)
