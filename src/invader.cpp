//
// Created by Sihnor on 16/09/2024.
//
#include "invader.h"

#include <cstdio>


void InitInvader(Invader* invader, const char* modelPath, const Vector3 position) {
    invader->active = true;

    invader->model = LoadModel(modelPath);
    invader->position = position;
    invader->direction = MOVE_RIGHT;
    invader->speed = 0.01;
    invader->offset = 0.0f;
}

void UpdateInvader(Invader* invader) {
    if (invader->active)
    {
        if (invader->direction == MOVE_DOWN) {
            invader->offset += invader->speed;
            invader->position.z += invader->speed;

            if (invader->offset > 1.0f) {
                invader->direction = (invader->lastDirection == MOVE_LEFT) ? MOVE_RIGHT : MOVE_LEFT;
                invader->offset = 0.0f;
            }
        }

        if (invader->direction == MOVE_RIGHT) {
            invader->position.x += invader->speed;
            invader->offset += invader->speed;

            if (invader->offset > 5.0f) {
                invader->lastDirection = MOVE_RIGHT;
                invader->direction = MOVE_DOWN;
                invader->offset = 0.0f;
            }
        }

        if (invader->direction == MOVE_LEFT) {
            invader->position.x -= invader->speed;
            invader->offset += invader->speed;

            if (invader->offset > 5.0f) {
                invader->lastDirection = MOVE_LEFT;
                invader->direction = MOVE_DOWN;
                invader->offset = 0.0f;
            }
        }
    }
}

void RenderInvader(const Invader* invader) {
    if (invader->active) {
        DrawModelEx(invader->model, invader->position, (Vector3){ 1.0f, 0.0f, 0.0f }, 60.0f, (Vector3){ 0.1f, 0.1f, 0.1f }, RED);
    }
}

void OnDeathInvader(Invader* invader)
{
    Sound fx = LoadSound("resources/sounds/invaderkilled.wav");
    PlaySound(fx);
    invader->active = false;
    invader->position = (Vector3){ 100.0f, -100.0f, -100.0f };
}

void UnloadInvader(const Invader* invader) {
    UnloadModel(invader->model);
}