#include <cstdlib>

// i hate this include syntax but i cant change it so im just gonna stick with this :/
#include "raylib.h"

#include "Renderer/Renderer.h"

int main()
{
    auto *renderer = new Snowflake::Renderer();

    renderer->CreateWindow(1920, 1080, ":3c", 60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Hello World :3c", 0, 0, 20, LIGHTGRAY);

        EndDrawing();
    }

    renderer->DestroyWindow();
    delete renderer;

    return 0;
}
