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
    Model model;
} Invader;

void InitInvader(Invader *invader, const char* modelPath);
void UpdateInvader(Invader *invader);
void RenderInvader(const Invader *invader);
void OnDeathInvader(Invader *invader);
void UploadInvader(Invader* invader);


#endif //INVADER_H
