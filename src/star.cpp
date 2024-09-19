//
// Created by Sihnor on 19/09/2024.
//

#include "star.h"

void InitStarField(StarField *starField)
{
    for (int i = 0; i < MAX_STARS; i++)
    {
        starField->stars[i].position = (Vector3){(float)GetRandomValue(0, GetScreenWidth()), (float)GetRandomValue(0, GetScreenHeight()), (float)GetRandomValue(0, 200)};
        starField->stars[i].speed = (float)GetRandomValue(1, 10);
        starField->stars[i].color = WHITE;
    }
}

void UpdateStarField(StarField* starField)
{
    for (int i = 0; i < MAX_STARS; i++) {
        // Stern bewegt sich in Z-Richtung (nach vorne)
        starField->stars[i].position.z += starField->stars[i].speed;

        // Wenn der Stern zu nahe kommt, wird er zurückgesetzt
        if (starField->stars[i].position.z > 0.0f) {
            starField->stars[i].position.z = GetRandomValue(-10, -1);
            starField->stars[i].position.x = GetRandomValue(-10, 10);
            starField->stars[i].position.y = GetRandomValue(-10, 10);
        }
    }
}

void RenderStarField(StarField* starField) {
    for (int i = 0; i < MAX_STARS; i++) {
        DrawSphere(starField->stars[i].position, 0.05f, starField->stars[i].color);
    }
}