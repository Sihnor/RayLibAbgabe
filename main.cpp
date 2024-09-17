
#include "raylib.h"
#include "src/game.h"
#include "src/enums/GameScreen.h"


int main()
{
    InitWindow(800, 600, "3D Space Invader");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    // Definiere den aktuellen Spielzustand
    GameScreen currentScreen = MENU_MAIN;

    // Definiere Schaltflächenparameter
    Rectangle startButton = { 300, 200, 200, 50 };
    Rectangle settingsButton = { 300, 270, 200, 50 };
    Rectangle quitButton = { 300, 340, 200, 50 };

    float volume = 0.5f;
    Rectangle volumeSlider = { 300, 200, 200, 20 };

    Game game;
    InitGame(&game);
    InitAudioDevice();

    Sound fx = LoadSound("resources/sounds/spaceinvaders.wav");
    PlaySound(fx);

    while (!WindowShouldClose())
    {
        if (currentScreen == GAME_PLAY)
        {
            UpdateGame(&game);
            RenderGame(&game);

            // Zurück zum Hauptmenü
            if (IsKeyPressed(KEY_ESCAPE)) {
                currentScreen = MENU_MAIN;
            }
            continue;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (currentScreen == MENU_MAIN)
        {
            DrawText("HAUPTMENU", 300, 100, 40, DARKGRAY);

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
            DrawText("Einstellungen", 300, 150, 40, DARKGRAY);
            DrawText("Lautstärke", 300, 200, 20, DARKGRAY);

            DrawRectangleRec(volumeSlider, LIGHTGRAY);
            DrawRectangle((int)(volumeSlider.x + (volumeSlider.width * volume)), volumeSlider.y - 5, 10, 30, RED);  // Schieberegler

            // Aktualisiere die Lautstärke, wenn der Slider verschoben wird
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), volumeSlider)) {
                volume = (GetMousePosition().x - volumeSlider.x) / volumeSlider.width;
                if (volume < 0.0f) volume = 0.0f;  // Begrenze die Lautstärke auf 0.0 (stumm)
                if (volume > 1.0f) volume = 1.0f;  // Begrenze die Lautstärke auf 1.0 (volle Lautstärke)
            }

            // Setze die Lautstärke für das gesamte Spiel
            SetMasterVolume(volume);

            DrawText(TextFormat("Lautstärke: %d%%", (int)(volume * 100)), 320, 250, 20, DARKGRAY);

            DrawText("Drücke [ESC] um zurückzukehren", 220, 300, 20, DARKGRAY);
            // Zurück zum Hauptmenü
            if (IsKeyPressed(KEY_ESCAPE)) {
                currentScreen = MENU_MAIN;
            }
        }

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}
