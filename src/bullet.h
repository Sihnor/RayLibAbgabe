//
// Created by Sihnor on 16/09/2024.
//

#ifndef BULLET_H
#define BULLET_H
#include "particle.h"
#include "raylib.h"

typedef struct BULLET
{
    Vector3 position;
    bool active;
    float speed;
    ParticleSystem particleSystem;
} Bullet;

void InitBullet(Bullet* bullet);
void UpdateBullet(Bullet* bullet);
void RenderBullet(Bullet* bullet);
void FireBullet(Bullet* bullet, Vector3 playerPosition);

#endif //BULLET_H
