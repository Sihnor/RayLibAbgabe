//
// Created by Sihnor on 16/09/2024.
//
#include "invader.h"

void InitInvader(Invader* invader) {
    const float x = GetRandomValue(-5, 5);
    const float z = GetRandomValue(-10, -1);
    invader->position = (Vector3){ x, 0.0f, z };
    invader->active = true;
}

void UpdateInvader(Invader* invader) {
    if (invader->active) {
        invader->position.z += 0.01f;
        if (invader->position.z > 5.0f) {
            const float x = GetRandomValue(-5, 5);
            const float z = GetRandomValue(-10, -1);
            invader->position = (Vector3){ x, 0.0f, z };
        }
    }
}

void RenderInvader(Invader* invader) {
    if (invader->active) {
        DrawCube(invader->position, 1.0f, 1.0f, 1.0f, RED);
    }
}

void OnDeathInvader(Invader* invader)
{
    invader->active = false;
    invader->position = (Vector3){ 100.0f, 100.0f, 100.0f };
}
