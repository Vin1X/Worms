#include "raylib.h"
#include "game.hpp"

Game::Game() {}

Game::~Game() {}

void Game::Init() {
    map.Init();
    int playerNumber = 1;
    for (auto &player : player) {
        player.Init(playerNumber);
        playerNumber++;
    }
}

void Game::Update() {
    player[0].projectile.Update();
    player[1].projectile.Update();
    bool player1Hit = CheckCollisionCircleRec(player[0].projectile.position, player[0].projectile.projectileRadius, player[1].GetRect());
    bool self1Hit = CheckCollisionCircleRec(player[0].projectile.position, player[0].projectile.projectileRadius + 20, player[0].GetRect());
    bool mapImpact1 = CheckCollisionCircleRec(player[0].projectile.position, player[0].projectile.projectileRadius, map.mapShape);

    bool player2Hit = CheckCollisionCircleRec(player[1].projectile.position, player[1].projectile.projectileRadius, player[0].GetRect());
    bool self2Hit = CheckCollisionCircleRec(player[1].projectile.position, player[1].projectile.projectileRadius + 20, player[1].GetRect());
    bool mapImpcat2 = CheckCollisionCircleRec(player[1].projectile.position, player[1].projectile.projectileRadius, map.mapShape);

    // Refactor to new function Impact() ?
    // Projectile1 & Map
    if (mapImpact1) {
        player[0].projectile.active = false;
        DrawText("Impact", GetScreenWidth() / 2 - MeasureText("Impact", 20) / 2, GetScreenHeight() / 2, 20, RED);
        if (!self1Hit) player[0].projectile.Explosion();
    }
    // Projectile1 & P2
    if (player1Hit && player[0].projectile.active) {
        player[1].health -= 20;
        player[0].projectile.active = false;
        DrawText("Impact", GetScreenWidth() / 2 - MeasureText("Impact", 20) / 2, GetScreenHeight() / 2, 20, RED);
    }
    // Projectile2 & Map
    if (mapImpcat2) {
        player[1].projectile.active = false;
        DrawText("Impact", GetScreenWidth() / 2 - MeasureText("Impact", 20) / 2, GetScreenHeight() / 2, 20, RED);
        if (!self2Hit) player[1].projectile.Explosion();
    }
    // Projectile2 & P1
    if (player2Hit && player[0].projectile.active) {
        player[0].health -= 20;
        player[1].projectile.active = false;
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
    Player& currentPlayerRef = player[currentPlayer];
    Player& nextPlayerRef = player[(currentPlayer + 1) % 2];

    if (!pause && !GameOver() && !nextPlayerRef.projectile.active) {
        currentPlayerRef.playerTurn = true;
        currentPlayerRef.TakeAim();
        if (currentPlayerRef.moves > 0) {
            if (currentPlayerRef.Move()) {
                currentPlayerRef.moves--;
                moves = currentPlayerRef.moves; 
            }
        }
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            currentPlayerRef.projectile.active = true; 
            currentPlayerRef.projectile.position = {currentPlayerRef.position.x + 10, currentPlayerRef.position.y + 25}; 
            currentPlayerRef.projectile.velocity = currentPlayerRef.velocity; 
            currentPlayerRef.playerTurn = false;
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
