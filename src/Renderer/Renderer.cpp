//
// Created by WolfPlay on 6/26/2024.
//

#include "Renderer.h"

#include "globals.h"
#include "raylib.h"
#include "spdlog/spdlog.h"

namespace Snowflake {
Renderer::Renderer() {
    _wasWindowCreated = false;
    _gameScenePtr = nullptr;
}

void Renderer::CreateWindow(unsigned short width, unsigned short height, const char *title, int targetFps)
{
    spdlog::info("Creating window W:{} H:{} FPS:{}", width, height, targetFps);
    InitWindow(width, height, title);
    SetTargetFPS(targetFps);
    _wasWindowCreated = true;
}

void Renderer::CreateWindow(unsigned short width, unsigned short height, const char *title, const char *iconPath,
                            int targetFps)
{
    InitWindow(width, height, title);
    SetWindowIcon(LoadImage(iconPath));
    SetTargetFPS(targetFps);
    _wasWindowCreated = true;
}

void Renderer::DestroyWindow() const
{
    if (_wasWindowCreated) { CloseWindow(); }
}

void Renderer::loadGameScene(GameScene* gameScene) {
    _gameScenePtr = gameScene;
}

void Renderer::gameLoop() const {
    do {
        g_mousePos = GetMousePosition();

        _gameScenePtr->update();

        BeginDrawing();
        ClearBackground(BLACK);

        _gameScenePtr->render();

        EndDrawing();
    } while (!WindowShouldClose());
}
}
