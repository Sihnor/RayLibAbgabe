//
// Created by Sihnor on 16/09/2024.
//

#include "raylib.h"
#include "game.h"

#include "star.h"

void InitGame(Game* game)
{
    // Kamera initialisieren
    game->camera.position = (Vector3){ 0, 0, 0 };
    game->camera.target = (Vector3){ 0, 0, 0 };
    game->camera.up = (Vector3){ 0, 1, 0 };
    game->camera.fovy = 45.0f;
    game->camera.projection = CAMERA_PERSPECTIVE;
    game->gameState = 0;
    game->deadInvaders = 0;

    // Spieler initialisieren
    InitPlayer(&game->player);

    // Invader initialisieren
    const char* invaderModelPath = "resources/SpaceInvader.obj";
    int index = 0;
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            const float posX = x * 1.5f - 7.0f;
            const float posZ = y * 1.5f - 10.0f;
            InitInvader(&game->invaders[index], invaderModelPath, (Vector3){ posX, 0.0f, posZ });
            index++;
        }
    }

    // Kuglen initialisieren
    InitBullet(&game->bullet);

    //InitStarField(&game->starField);
}

void UpdateGame(Game* game) {
    // Kamera auf den Spieler fokussieren
    game->camera.position = (Vector3){ game->player.position.x, 10.0f, 10.0f };
    game->camera.target = (Vector3){ game->player.position.x, 0.0f, 0.0f };

    // Spieler und Kugel bewegen
    UpdatePlayer(&game->player);
    if (IsKeyPressed(KEY_SPACE)) {
        FireBullet(&game->bullet, game->player.position);
    }
    UpdateBullet(&game->bullet);

    // Invader bewegen und Kollision prüfen
    for (auto & invader : game->invaders) {
        UpdateInvader(&invader);
        if (game->bullet.active && CheckCollisionSpheres(game->bullet.position, 0.2f, invader.position, 0.5f)) {
            OnDeathInvader(&invader);
            game->deadInvaders++;
            game->bullet.active = false;
        }

        if (invader.position.z > 3.5f)
        {
            game->gameState = 2;
        }
    }

    if (game->deadInvaders == MAX_INVADERS) {
        game->deadInvaders = 0;
        game->gameState = 1;
    }

    //UpdateStarField(&game->starField);
}

void RenderGame(Game* game) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    BeginMode3D(game->camera);

    //RenderStarField(&game->starField);

    // Spieler und Objekte zeichnen
    RenderPlayer(&game->player);
    RenderBullet(&game->bullet);

    for (int i = 0; i < MAX_INVADERS; i++) {
        RenderInvader(&game->invaders[i]);
    }

    EndMode3D();

    DrawText("Bewege mit Links/Rechts, Schieße mit Leertaste", 10, 10, 20, DARKGRAY);

    EndDrawing();
}

int GameState(Game* game) {
    return game->gameState;
}

void SetGameSpeed(Game* game, float speed) {
    for (auto& invader : game->invaders) {
        invader.speed = speed;
    }
}