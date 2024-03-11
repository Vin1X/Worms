#include "raylib.h"
#include "game.hpp"

Game::Game() {}

Game::~Game() {}

void Game::Init() {
    map.Init();
    player[0].Init(1);
    player[1].Init(2);
    projectile[0].Init();
    projectile[1].Init();
}

void Game::Update() {
    projectile[0].Update();
    projectile[1].Update();
    bool player1Hit = CheckCollisionCircleRec(projectile[0].position, projectile[0].projectileRadius, player[1].GetRect());
    bool self1Hit = CheckCollisionCircleRec(projectile[0].position, projectile[0].projectileRadius + 20, player[0].GetRect());
    bool mapImpact1 = CheckCollisionCircleRec(projectile[0].position, projectile[0].projectileRadius, map.mapShape);

    bool player2Hit = CheckCollisionCircleRec(projectile[1].position, projectile[1].projectileRadius, player[0].GetRect());
    bool self2Hit = CheckCollisionCircleRec(projectile[1].position, projectile[1].projectileRadius + 20, player[1].GetRect());
    bool mapImpcat2 = CheckCollisionCircleRec(projectile[1].position, projectile[1].projectileRadius, map.mapShape);

    // Refactor to new function Impact() ?
    // Projectile1 & Map
    if (mapImpact1) {
        projectile[0].active = false;
        DrawText("Impact", GetScreenWidth() / 2 - MeasureText("Impact", 20) / 2, GetScreenHeight() / 2, 20, RED);
        if (!self1Hit) projectile[0].Explosion();
    }
    // Projectile1 & P2
    if (player1Hit && projectile[0].active) {
        player[1].health -= 20;
        projectile[0].active = false;
        DrawText("Impact", GetScreenWidth() / 2 - MeasureText("Impact", 20) / 2, GetScreenHeight() / 2, 20, RED);
    }
    // Projectile2 & Map
    if (mapImpcat2) {
        projectile[1].active = false;
        DrawText("Impact", GetScreenWidth() / 2 - MeasureText("Impact", 20) / 2, GetScreenHeight() / 2, 20, RED);
        if (!self2Hit) projectile[1].Explosion();
    }
    // Projectile2 & P1
    if (player2Hit && projectile[1].active) {
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
    if (GameOver() && IsKeyPressed(KEY_ENTER)) {
        player[0].health = 100;
        player[1].health = 100;
        currentPlayer = 0;
        round = 0;
    }
}

void Game::Rounds() {
    // Each Player has a turn with a set amount of moves and a shot
    if (!pause && !GameOver()) {
        player[currentPlayer].playerTurn = true;
        player[currentPlayer].TakeAim();
        if (player[currentPlayer].moves > 0) {
            if (player[currentPlayer].Move()) {
                player[currentPlayer].moves--;
                moves = player[currentPlayer].moves; // Das hier abändern, projectile soll Teil vom Player sein
            }
        }
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            projectile[currentPlayer].active = true; // Das hier abändern
            projectile[currentPlayer].position = {player[currentPlayer].position.x + 10, player[currentPlayer].position.y + 25}; // Das hier abändern
            projectile[currentPlayer].velocity = player[currentPlayer].velocity; // Das hier abändern
            player[currentPlayer].playerTurn = false;
            currentPlayer = (currentPlayer + 1) % 2;
            player[currentPlayer].moves = 5;
            player[currentPlayer].playerTurn = true;
            if (currentPlayer == 0) round++;
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
