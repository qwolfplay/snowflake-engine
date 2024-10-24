//
// Created by WolfPlay on 6/26/2024.
//

#ifndef SNOWFLAKE_RENDERER_H
#define SNOWFLAKE_RENDERER_H

#include <chrono>

#include "raylib.h"

#include "GameScene.class/GameScene.h"

#define FRAME_TIME_AVG_ARR_LEN 256

namespace Snowflake
{
    class Renderer {
        bool _wasWindowCreated;
        GameScene* _gameScenePtr;

        std::chrono::time_point<std::chrono::milliseconds> _frameTime;

    public:
        Renderer();

        void initRenderer(); // TODO

        void CreateWindow(unsigned short width, unsigned short height, const char *title, int targetFps);

        void CreateWindow(unsigned short width, unsigned short height, const char *title, const char *iconPath,
                          int targetFps);

        void DestroyWindow() const;

        void loadGameScene(GameScene* gameScene);

        void gameLoop() const;

    };
}

#endif //SNOWFLAKE_RENDERER_H
