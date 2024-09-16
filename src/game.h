//
// Created by Sihnor on 16/09/2024.
//

#ifndef GAME_H
#define GAME_H

#include "bullet.h"
#include "invader.h"
#include "player.h"
#include "raylib.h"

#define MAX_INVADERS 10

typedef struct Game
{
    Camera camera;
    Player player;
    Invader invaders[MAX_INVADERS];
    Bullet bullet;
} Game;

void InitGame(Game *game);
void UpdateGame(Game *game);
void RenderGame(Game *game);

#endif //GAME_H