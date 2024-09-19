//
// Created by Sihnor on 19/09/2024.
//

#ifndef STAR_H
#define STAR_H
#include "raylib.h"

#define MAX_STARS 100

typedef struct STAR
{
    Vector3 position;
    float speed;
    Color color;
}Star;

typedef struct STARFIELD
{
    Star stars[MAX_STARS];
}StarField;

void InitStarField(StarField *starField);
void UpdateStarField(StarField *starField);
void RenderStarField(StarField *starField);

#endif //STAR_H
