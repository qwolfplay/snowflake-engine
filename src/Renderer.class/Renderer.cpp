//
// Created by WolfPlay on 6/26/2024.
//

#include "Renderer.h"

#include "raylib.h"

void Renderer::CreateWindow(unsigned short width, unsigned short height, const char *title, int targetFps)
{
    InitWindow(width, height, title);
    SetTargetFPS(targetFps);
    _wasWindowCreated = true;
}

void Renderer::CreateWindow(unsigned short width, unsigned short height, const char *title, const char *iconPath, int targetFps)
{
    InitWindow(width, height, title);
    SetWindowIcon(LoadImage(iconPath));
    SetTargetFPS(targetFps);
    _wasWindowCreated = true;
}

void Renderer::DestroyWindow()
{
    if (_wasWindowCreated) { CloseWindow(); }
}
