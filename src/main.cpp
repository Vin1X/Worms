#include <iostream>
#include "raylib.h"
#include "player.hpp"
#include "map.hpp"
#include "projectile.hpp"
#include "impact.hpp"
#include "game.hpp"
#include "ui.hpp"

/*/ GLOBAL DEFINITIONS /*/
Game game;
Ui ui;

int main() {
    InitWindow(ui.screenWidth, ui.screenHeight, "Worms");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        if (!game.gameStart) {
            ui.Init();
        }
        else {
            game.Init();
            game.Update();
            if (game.GameOver()) {
                ui.GameOver();
            }

            // Begin with Player 1
            game.Rounds();

            ui.Rounds(game.round, game.moves);
        }
        if (game.pause && game.gameStart && !game.GameOver()) ui.Pause();

        game.HandleInput();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
