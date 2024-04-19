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

    // Initialization game and UI
    Ui ui(screenWidth, screenHeight);
    Game game(ui);

    while (!WindowShouldClose())
    {

        BeginDrawing();

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
