//
// Created by WolfPlay on 6/26/2024.
//

#ifndef SNOWFLAKE_RENDERER_H
#define SNOWFLAKE_RENDERER_H

#include "raylib.h"

class Renderer {
    bool _wasWindowCreated;
public:
    Renderer() = default;

    void CreateWindow(unsigned short width, unsigned short height, const char* title, int targetFps);

    void CreateWindow(unsigned short width, unsigned short height, const char* title, const char* iconPath, int targetFps);

    void DestroyWindow();

//    static void RenderScene();
};

#endif //SNOWFLAKE_RENDERER_H
