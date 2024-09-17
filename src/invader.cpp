//
// Created by Sihnor on 16/09/2024.
//
#include "invader.h"

void InitInvader(Invader* invader, const char* modelPath) {
    const float x = GetRandomValue(-5, 5);
    const float z = GetRandomValue(-10, -1);
    invader->position = (Vector3){ x, 0.0f, z };
    invader->active = true;

    invader->model = LoadModel(modelPath);
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
    invader->position = (Vector3){ 100.0f, 100.0f, 100.0f };
}

void UnloadInvader(const Invader* invader) {
    UnloadModel(invader->model);
}