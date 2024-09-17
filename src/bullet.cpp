//
// Created by Sihnor on 16/09/2024.
//
#include "bullet.h"

#include <cstdio>


void InitBullet(Bullet* bullet) {
    bullet->position = (Vector3){ 0.0f, -10.0f, 0.0f }; // Inaktive Position
    bullet->active = false;
    bullet->speed = 10.0f;
    InitParticleSystem(&bullet->particleSystem);
}

void UpdateBullet(Bullet* bullet) {
    if (bullet->active) {
        bullet->position.z -= bullet->speed * GetFrameTime();

        EmitParticle(&bullet->particleSystem, bullet->position);

        UpdateParticleSystem(&bullet->particleSystem);

        // Deaktiviere Bullet, wenn sie den Bildschirm verlässt
        if (bullet->position.z < -10.0f) bullet->active = false;
    }

    UpdateParticleSystem(&bullet->particleSystem);
}

void RenderBullet(Bullet* bullet) {
    if (bullet->active) {
        DrawSphere(bullet->position, 0.2f, GREEN);
    }
    RenderParticleSystem(&bullet->particleSystem);
}

void FireBullet(Bullet* bullet, Vector3 playerPosition) {
    if (!bullet->active) {
        bullet->position = playerPosition;
        bullet->active = true;
    }
}
