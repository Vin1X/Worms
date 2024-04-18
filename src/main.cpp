#include <iostream>
#include <raylib.h>
#include "game.hpp"

/*/ GLOBAL DEFINITIONS /*/
int screenWidth = 1280;
int screenHeight = 720;
Game game;

int main()
{
    // Initialization of game window
    InitWindow(screenWidth, screenHeight, "Worms");
    SetTargetFPS(60);

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
