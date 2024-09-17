//
// Created by Sihnor on 16/09/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"

typedef struct PLAYER
{
    Vector3 position;
    float speed;
} Player;

void InitPlayer(Player *player);
void UpdatePlayer(Player *player);
void RenderPlayer(Player *player);

#endif //PLAYER_H
