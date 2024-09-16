
#include "raylib.h"
#include "src/game.h"


int main()
{
    InitWindow(800, 600, "3D Space Invader");
    SetTargetFPS(60);

    Game game;
    InitGame(&game);

    while (!WindowShouldClose())
    {
        UpdateGame(&game);
        RenderGame(&game);
    }

    CloseWindow();

    return 0;
}
