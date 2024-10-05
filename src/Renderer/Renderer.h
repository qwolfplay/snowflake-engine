//
// Created by WolfPlay on 6/26/2024.
//

#ifndef SNOWFLAKE_RENDERER_H
#define SNOWFLAKE_RENDERER_H

#include "raylib.h"

namespace Snowflake
{
    class Renderer
    {
        bool _wasWindowCreated;


    public:
        Renderer() = default;

        void initRenderer(); // TODO

        void CreateWindow(unsigned short width, unsigned short height, const char *title, int targetFps);

        void CreateWindow(unsigned short width, unsigned short height, const char *title, const char *iconPath,
                          int targetFps);

        void DestroyWindow() const;
    };
}

#endif //SNOWFLAKE_RENDERER_H
