//
// Created by Sihnor on 16/09/2024.
//

#ifndef INVADER_H
#define INVADER_H
#include "raylib.h"

typedef struct Invader
{
    Vector3 position;
    bool active;
} Invader;

void InitInvader(Invader *invader);
void UpdateInvader(Invader *invader);
void RenderInvader(Invader *invader);
void OnDeathInvader(Invader *invader);

#endif //INVADER_H
