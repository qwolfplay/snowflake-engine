#include <cstdlib>

// i hate this include syntax but i cant change it so im just stuck with this :/
#include "raylib.h"

int main()
{
    const unsigned short WIDTH  = 800;
    const unsigned short HEIGHT = 600;

    InitWindow(800, 600, ":3");

    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(DARKGRAY);
        DrawText(":3 nya~~", 400, 300, 40, RAYWHITE);

        EndDrawing();
    }

    return 0;
}
