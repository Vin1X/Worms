#include <iostream>
#include "raylib.h"
#include "player.hpp"
#include "map.cpp"
#include "projectile.hpp"

/*/ GLOBAL DEFINITIONS /*/
int screenWidth = 1280;
int screenHeight = 720;

Rectangle mapShape = {0, 600, 1280, 250}; // x, y, width, height
Vector2 startingPosition = {50, mapShape.y - 50}; // x, y

Map map(mapShape, BLACK);
Player player(startingPosition); // x, y
Projectile projectile(player.position); // x, y

int main() {
    InitWindow(screenWidth, screenHeight, "Worms");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        map.init();
        player.init();

        player.move();
        player.takeAim();
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            projectile.active = true;
            projectile.position = {player.position.x + 10, player.position.y + 25};
        }
        projectile.init();
        projectile.update();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
