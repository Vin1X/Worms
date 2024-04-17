#include <iostream>
#include <raylib.h>
#include "game.hpp"
#include "ui.hpp"

/*/ GLOBAL DEFINITIONS /*/
Game game;
Ui ui;

int main()
{
    // Initialization of game window
    InitWindow(ui.screenWidth, ui.screenHeight, "Worms");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        // Starting window
        if (!game.gameStart)
        {
            ui.Init();
        }
        else
        {
            // Game initialization
            game.Init();
            game.Update();
            if (game.GameOver())
            {
                ui.GameOver();
            }

            // Begin with Player 1
            game.Rounds();

            ui.Rounds(game.round, game.moves);
        }
        // Pause window
        if (game.pause) ui.Pause();

        game.HandleInput();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
