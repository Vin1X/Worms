#include "raylib.h"
#include "game.hpp"

Game::Game() {}

Game::~Game() {}

void Game::Init() {
    map.Init();
    player2.Init(2, gameStart);
    player.Init(1, gameStart);
    projectile.Init();
    projectile2.Init();

    

}

void Game::Update() {

    if (!pause) {
        projectile.Update();
        projectile2.Update();
        //player.Move();
        //player2.Move();
        //player.TakeAim();
        //player2.TakeAim();
    }
    if (CheckCollisionCircleRec(projectile.position, projectile.projectileRadius, map.mapShape)) {
        projectile.active = false;
        DrawText("Impact", GetScreenWidth() / 2 - MeasureText("Impact", 20) / 2, GetScreenHeight() / 2, 20, RED);
        map.Explosion(projectile.position);
    }
    if (CheckCollisionCircleRec(projectile2.position, projectile2.projectileRadius, map.mapShape)) {
        projectile2.active = false;
        DrawText("Impact", GetScreenWidth() / 2 - MeasureText("Impact", 20) / 2, GetScreenHeight() / 2, 20, RED);
        map.Explosion(projectile2.position);
    }
    if (CheckCollisionCircleRec(projectile.position, projectile.projectileRadius, player2.GetRect()) && projectile.active) {
        player2.health -= 20;
        projectile.active = false;
        DrawText("Impact", GetScreenWidth() / 2 - MeasureText("Impact", 20) / 2, GetScreenHeight() / 2, 20, RED);
    }
    if (CheckCollisionCircleRec(projectile2.position, projectile2.projectileRadius, player.GetRect()) && projectile2.active) {
        player.health -= 20;
        projectile2.active = false;
        DrawText("Impact", GetScreenWidth() / 2 - MeasureText("Impact", 20) / 2, GetScreenHeight() / 2, 20, RED);
    }
}

void Game::HandleInput() {
    /*if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        projectile.active = true;
        projectile.position = {player.position.x + 10, player.position.y + 25};
        projectile.velocity = player.velocity;
    }*/

    /*if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) player.position.x += 10;
    else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) player.position.x -= 10;*/

    if (IsKeyPressed(KEY_P)) {
        pause = !pause;
    }
    if (IsKeyPressed(KEY_ENTER)) {
        gameStart = true;
    }
}

void Game::Rounds() {
    //Each Player has a turn with a set amount of moves and shots
    //Player 1
    if (currentPlayer == 1) {
        player.playerTurn = true;
        player.TakeAim();
        player.Move();
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            projectile.active = true;
            projectile.position = {player.position.x + 10, player.position.y + 25};
            projectile.velocity = player.velocity;
            currentPlayer = 2;
            player2.playerTurn = true;
            shots--;
        }
    } else  if (currentPlayer == 2) {
        player2.playerTurn = true;
        player2.TakeAim();
        player2.Move();
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            projectile2.active = true;
            projectile2.position = {player2.position.x + 10, player2.position.y + 25};
            projectile2.velocity = player2.velocity;
            currentPlayer = 1;
            player.playerTurn = true;
            shots--;
        }
    }
    //round++;


    //Player 2
}

bool Game::GameOver() {
    if (player.health <= 0) {
        return true;
    } else if (player2.health <= 0) {
        return true;
    } else {
        return false;
    }
}