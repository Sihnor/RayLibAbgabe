//
// Created by Sihnor on 17/09/2024.
//

#ifndef PARTICLE_H
#define PARTICLE_H
#include "raylib.h"

#define MAX_PARTICLES 100

typedef struct PARTICLE
{
    Vector3 position;
    Vector3 velocity;
    float lifetime;
    bool active;
} Particle;

typedef struct ParticleSystem
{
    Particle particles[MAX_PARTICLES];
} ParticleSystem;

void InitParticleSystem(ParticleSystem* particleSystem);
void EmitParticle(ParticleSystem* particleSystem, Vector3 position);
void UpdateParticleSystem(ParticleSystem* particleSystem);
void RenderParticleSystem(const ParticleSystem* particleSystem);


#endif //PARTICLE_H
