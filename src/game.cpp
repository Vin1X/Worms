#include "raylib.h"
#include "game.hpp"

Game::Game() {}

Game::~Game() {}

void Game::Init() {
    map.Init();
    player2.Init(2);
    player.Init(1);
    projectile.Init();

    if (CheckCollisionCircleRec(projectile.position, projectile.projectileRadius, map.mapShape)) {
        projectile.active = false;
        DrawText("Impact", GetScreenWidth() / 2, GetScreenHeight() / 2, 20, RED);
        map.Explosion(projectile.position);
    }

}

void Game::Update() {
    //player.Move();
    //layer2.Move();
    player.TakeAim();
    player2.TakeAim();

    projectile.Update();

}

void Game::HandleInput() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        projectile.active = true;
        projectile.position = {player.position.x + 10, player.position.y + 25};
        projectile.velocity = player.velocity;
    }
    if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) player.position.x += 10;
    else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) player.position.x -= 10;
}

void Game::Rounds() {
    //Each Player has a turn with a set amount of moves and shots
    //Player 1
    player.playerTurn = true;
    


    //Player 2
}