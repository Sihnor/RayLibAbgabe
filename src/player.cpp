//
// Created by Sihnor on 16/09/2024.
//
#include "player.h"

#include <cstdio>

void InitPlayer(Player* player) {
    player->position = (Vector3){ 0.0f, 0.0f, 4.0f };
    player->speed = 4.0f;
}

void UpdatePlayer(Player* player) {
    if (IsKeyDown(KEY_RIGHT) && player->position.x < 10) player->position.x += player->speed * GetFrameTime();
    if (IsKeyDown(KEY_LEFT) && player->position.x > -10) player->position.x -= player->speed * GetFrameTime();

}

void RenderPlayer(Player* player) {
    DrawCube(player->position, 1.0f, 1.0f, 1.0f, BLUE);
}