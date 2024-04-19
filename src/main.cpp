#include <iostream>
#include <raylib.h>
#include "game.hpp"
#include "ui.hpp"

/*/ GLOBAL DEFINITIONS /*/
int screenWidth = 1280;
int screenHeight = 720;

int main()
{
    // Initialization of game window
    InitWindow(screenWidth, screenHeight, "Worms");
    SetTargetFPS(60);

    // Initialization audio and background music
    InitAudioDevice();
    Music music;
    music = LoadMusicStream("resources/sounds/After the Storm.mp3");
    SetMusicVolume(music, 0.1);
    PlayMusicStream(music);

    Texture2D player;
    player = LoadTexture("resources/img/idle.png");

    // Initialization game and UI
    Ui ui(screenWidth, screenHeight);
    Game game(ui);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);

        BeginDrawing();

        DrawFPS(40, 40);
        DrawTexture(player, 0, 0, WHITE);
        // Handle user input
        game.HandleInput();

        // Game initialization
        game.Init();

        // Update projectiles and check for collisions
        game.Update();

        // Begin with Player 1
        game.Rounds();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
