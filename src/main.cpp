#include <iostream>
#include "raylib.h"
#include "player.hpp"
#include "map.hpp"
#include "projectile.hpp"
#include "impact.hpp"
#include "game.hpp"

/*/ GLOBAL DEFINITIONS /*/
int screenWidth = 1280;
int screenHeight = 720;
Game game;

int main() {
    InitWindow(screenWidth, screenHeight, "Worms");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        game.HandleInput();
        game.Update();
        game.Init();
        game.Rounds();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
