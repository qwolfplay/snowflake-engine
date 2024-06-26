#include <cstdlib>

// i hate this include syntax but i cant change it so im just stuck with this :/
#include "raylib.h"

int main()
{
    const unsigned short WIDTH  = 800;
    const unsigned short HEIGHT = 600;

    InitWindow(1920, 1080, ":3");

    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(DARKGRAY);
        DrawText(":3 nya~~", 400, 300, 40, RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
