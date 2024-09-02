#include <iostream>
#include "raylib.h"

int main()
{
    InitWindow(600, 300, "Title");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("Hello World!", 20, 20, 30, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
