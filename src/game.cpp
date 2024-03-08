#include "raylib.h"
#include "game.hpp"

Game::Game() {}

Game::~Game() {}

void Game::Init() {
    map.Init();
    player[0].Init(1, gameStart);
    player[1].Init(2, gameStart);
    projectile[0].Init();
    projectile[1].Init();
}

void Game::Update() {
    if (!pause) {
        projectile[0].Update();
        projectile[1].Update();
    }

    // Refactor to new function UpdatePlayer() ?
    if (CheckCollisionCircleRec(projectile[0].position, projectile[0].projectileRadius, map.mapShape)) {
        projectile[0].active = false;
        DrawText("Impact", GetScreenWidth() / 2 - MeasureText("Impact", 20) / 2, GetScreenHeight() / 2, 20, RED);
        projectile[0].Explosion();
    }
    if (CheckCollisionCircleRec(projectile[1].position, projectile[1].projectileRadius, map.mapShape)) {
        projectile[1].active = false;
        DrawText("Impact", GetScreenWidth() / 2 - MeasureText("Impact", 20) / 2, GetScreenHeight() / 2, 20, RED);
        projectile[1].Explosion();
    }
    if (CheckCollisionCircleRec(projectile[0].position, projectile[0].projectileRadius, player[1].GetRect()) && projectile[0].active) {
        player[1].health -= 20;
        projectile[0].active = false;
        DrawText("Impact", GetScreenWidth() / 2 - MeasureText("Impact", 20) / 2, GetScreenHeight() / 2, 20, RED);
    }
    if (CheckCollisionCircleRec(projectile[1].position, projectile[1].projectileRadius, player[0].GetRect()) && projectile[1].active) {
        player[0].health -= 20;
        projectile[1].active = false;
        DrawText("Impact", GetScreenWidth() / 2 - MeasureText("Impact", 20) / 2, GetScreenHeight() / 2, 20, RED);
    }
}

void Game::HandleInput() {
    if (IsKeyPressed(KEY_P)) {
        pause = !pause;
    }
    if (!gameStart && IsKeyPressed(KEY_ENTER)) {
        gameStart = true;
    }
    if (GameOver()) {
        if (IsKeyPressed(KEY_ENTER)) {
            player[0].health = 100;
            player[1].health = 100;
            shots = 1;
            currentPlayer = 1;
            round = 0;
        }
    }
}

void Game::Rounds() {
    // Each Player has a turn with a set amount of moves and shots
    // New function to reduce redundancy!
    if (currentPlayer == 1) {
        player[0].playerTurn = true;
        player[0].TakeAim();
        player[0].Move();
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            projectile[0].active = true;
            projectile[0].position = {player[0].position.x + 10, player[0].position.y + 25};
            projectile[0].velocity = player[0].velocity;
            currentPlayer = 2;
            player[1].playerTurn = true;
            shots--;
        }
    } else  if (currentPlayer == 2) {
        player[1].playerTurn = true;
        player[1].TakeAim();
        player[1].Move();
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            projectile[1].active = true;
            projectile[1].position = {player[1].position.x + 10, player[1].position.y + 25};
            projectile[1].velocity = player[1].velocity;
            currentPlayer = 1;
            player[0].playerTurn = true;
            shots--;
        }
    }
}

bool Game::GameOver() {
    if (player[0].health <= 0) {
        return true;
    } else if (player[1].health <= 0) {
        return true;
    } else {
        return false;
    }
}
