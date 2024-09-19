//
// Created by Sihnor on 16/09/2024.
//

#ifndef INVADER_H
#define INVADER_H
#include "raylib.h"

#define MAX_INVADERS 30  // 10 (breit) x 3 (hoch)

typedef struct INVADER
{
    Vector3 position;
    bool active;
    Model model;
} Invader;

typedef enum
{
    MOVE_LEFT,
    MOVE_RIGHT,
} MoveDirection;

void InitInvader(Invader *invader, const char* modelPath, const Vector3 position);
void UpdateInvader(Invader *invader);
void RenderInvader(const Invader *invader);
void OnDeathInvader(Invader *invader);
void UploadInvader(Invader* invader);


#endif //INVADER_H
