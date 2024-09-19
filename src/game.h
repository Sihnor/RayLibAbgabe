//
// Created by Sihnor on 16/09/2024.
//

#ifndef GAME_H
#define GAME_H

#include "bullet.h"
#include "invader.h"
#include "player.h"
#include "raylib.h"
#include "star.h"

#define MAX_INVADERS 30

typedef struct GAME
{
    Camera camera;
    Player player;
    Invader invaders[MAX_INVADERS];
    Bullet bullet;
    int deadInvaders;
    int gameState;
    StarField starField;
} Game;

void InitGame(Game *game);
void UpdateGame(Game *game);
void RenderGame(Game *game);
int GameState(Game *game); // 0 = OnGoing, 1 = Win, 2 = Lose
void SetGameSpeed(Game *game, float speed);

#endif //GAME_H