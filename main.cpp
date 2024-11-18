
#include <cstdio>

#include "raylib.h"
#include "src/game.h"
#include "src/enums/GameScreen.h"


int main()
{
    //InitWindow(800, 600, "3D Space Invader");
    InitWindow(800, 600, "3D Space Invader");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);
    Image icon = LoadImage("resources/images/SpaceInvadersLogo.png");
    SetWindowIcon(icon);

    // Definiere den aktuellen Spielzustand
    GameScreen currentScreen = MENU_MAIN;

    // Definiere Schaltflächenparameter
    Rectangle startButton = { 300, 200, 200, 50 };
    Rectangle settingsButton = { 300, 270, 200, 50 };
    Rectangle quitButton = { 300, 340, 200, 50 };

    float volume = 0.5f;
    Rectangle volumeSlider = { 150, 200, 200, 20 };

    float speed = 0.1f;
    Rectangle speedSlider = { 450, 200, 200, 20 };

    Game game;
    InitGame(&game);
    InitAudioDevice();

    Sound fx = LoadSound("resources/sounds/spaceinvaders.wav");
    PlaySound(fx);

    SetMasterVolume(volume);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (currentScreen == GAME_PLAY)
        {
            SetGameSpeed(&game, speed);
            UpdateGame(&game);
            RenderGame(&game);
            if (GameState(&game) == 1) {
                currentScreen = GAME_WIN;
            }
            else if (GameState(&game) == 2) {
                currentScreen = GAME_OVER;
            }

            // Zurück zum Hauptmenü
            if (IsKeyPressed(KEY_ESCAPE)) {
                currentScreen = MENU_MAIN;
            }
            continue;
        }


        if (currentScreen == MENU_MAIN)
        {
            DrawText("HAUPTMENU", 280, 100, 40, DARKGRAY);

            // Schaltflächen zeichnen
            DrawRectangleRec(startButton, LIGHTGRAY);
            DrawText("Start", startButton.x + 60, startButton.y + 10, 20, BLACK);

            DrawRectangleRec(settingsButton, LIGHTGRAY);
            DrawText("Einstellungen", settingsButton.x + 20, settingsButton.y + 10, 20, BLACK);

            DrawRectangleRec(quitButton, LIGHTGRAY);
            DrawText("Quit", quitButton.x + 70, quitButton.y + 10, 20, BLACK);

            // Überprüfen, ob eine Schaltfläche angeklickt wird
            if (CheckCollisionPointRec(GetMousePosition(), startButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentScreen = GAME_PLAY;  // Wechselt zum Spiel
            }
            if (CheckCollisionPointRec(GetMousePosition(), settingsButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentScreen = MENU_SETTINGS;  // Wechselt zu den Einstellungen
            }
            if (CheckCollisionPointRec(GetMousePosition(), quitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                CloseWindow();  // Beendet das Spiel
            }
        }

        if (currentScreen == MENU_SETTINGS)
        {
            DrawText("Einstellungen", 280, 100, 40, DARKGRAY);

            DrawRectangleRec(volumeSlider, LIGHTGRAY);
            DrawRectangle((int)(volumeSlider.x + (volumeSlider.width * volume)), volumeSlider.y - 5, 10, 30, RED);  // Schieberegler

            DrawRectangleRec(speedSlider, LIGHTGRAY);
            DrawRectangle((int)(speedSlider.x + (speedSlider.width * speed)), speedSlider.y - 5, 10, 30, RED);  // Schieberegler

            // Aktualisiere die Lautstärke, wenn der Slider verschoben wird
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), volumeSlider)) {
                volume = (GetMousePosition().x - volumeSlider.x) / volumeSlider.width;
                if (volume < 0.0f) volume = 0.0f;  // Begrenze die Lautstärke auf 0.0 (stumm)
                if (volume > 1.0f) volume = 1.0f;  // Begrenze die Lautstärke auf 1.0 (volle Lautstärke)
            }

            // Aktualisiere die Geschwindigkeit, wenn der Slider verschoben wird
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), speedSlider)) {
                speed = (GetMousePosition().x - speedSlider.x) / speedSlider.width;
                if (speed <= 0.0f) speed = 0.01f;  // Begrenze die Geschwindigkeit auf 0.001
                if (speed > 1.0f) speed = 1.0f;  // Begrenze die Geschwindigkeit auf 0.1
                printf("Speed: %f\n", speed);
            }

            // Setze die Lautstärke für das gesamte Spiel
            SetMasterVolume(volume);

            DrawText(TextFormat("Lautstärke: %d%%", (int)(volume * 100)), 170, 250, 20, DARKGRAY);
            DrawText(TextFormat("Speed: %d%%", (int)(speed * 100)), 470, 250, 20, DARKGRAY);

            DrawText("Drücke [ESC] um zurückzukehren", 220, 300, 20, DARKGRAY);
            // Zurück zum Hauptmenü
            if (IsKeyPressed(KEY_ESCAPE)) {
                currentScreen = MENU_MAIN;
            }
        }

        if (currentScreen == GAME_WIN)
        {
            DrawText("GEWONNEN!", 300, 200, 40, DARKGRAY);
            DrawText("Drücke [ESC] um zurückzukehren", 220, 300, 20, DARKGRAY);
            // Zurück zum Hauptmenü
            if (IsKeyPressed(KEY_ESCAPE)) {
                InitGame(&game);
                currentScreen = MENU_MAIN;
            }
        }

        if (currentScreen == GAME_OVER)
        {
            DrawText("VERLOREN!", 300, 200, 40, DARKGRAY);
            DrawText("Drücke [ESC] um zurückzukehren", 220, 300, 20, DARKGRAY);
            // Zurück zum Hauptmenü
            if (IsKeyPressed(KEY_ESCAPE)) {
                InitGame(&game);
                currentScreen = MENU_MAIN;
            }
        }

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}
