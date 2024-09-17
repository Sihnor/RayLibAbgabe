//
// Created by Sihnor on 17/09/2024.
//

#include "particle.h"

#include <cstdio>

#include "raymath.h"

void InitParticleSystem(ParticleSystem* particleSystem)
{
    for (Particle particle : particleSystem->particles)
    {
        particle.active = false;
    }
}

void EmitParticle(ParticleSystem* particleSystem, Vector3 position)
{
    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        Particle* particle = &particleSystem->particles[i];

        if (!particle->active)
        {
            particle->position = position;

            const float velocityX = GetRandomValue(-1, 1);
            const float velocityY = GetRandomValue(-1, 1);
            const float velocityZ = GetRandomValue(-1, 1);
            particle->velocity = (Vector3){ velocityX, velocityY, velocityZ };
            particle->lifetime = 1.0f;
            particle->active = true;
            break;
        }
    }
}

void UpdateParticleSystem(ParticleSystem* particleSystem)
{
    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        Particle* particle = &particleSystem->particles[i];
        if (particle->active)
        {
            particle->lifetime -= GetFrameTime();
            if (particle->lifetime <= 0.0f)
                particle->active = false;
            else{
                particle->position.x += particle->velocity.x * GetFrameTime();
                particle->position.y += particle->velocity.y * GetFrameTime();
                particle->position.z += particle->velocity.z * GetFrameTime();
            }
        }
    }
}

Color LerpColor(Color start, Color end, float t)
{
    return (Color){
        (unsigned char)Lerp(start.r, end.r, t),
        (unsigned char)Lerp(start.g, end.g, t),
        (unsigned char)Lerp(start.b, end.b, t),
        (unsigned char)Lerp(start.a, end.a, t)
    };
}

void RenderParticleSystem(const ParticleSystem* particleSystem)
{
    for (const Particle particle : particleSystem->particles)
    {
        if (particle.active)
        {
            Color particleColor = LerpColor(YELLOW, RED, particle.lifetime);
            DrawSphere(particle.position, 0.1f, particleColor);
        }
    }
}


