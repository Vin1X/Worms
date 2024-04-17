#include <raylib.h>
#include "game.hpp"

Game::Game() {}

Game::~Game() {}

// Initialize players and map
void Game::Init()
{
    for (auto &player : player)
    {
        player.Init(playerNumber);
        playerNumber++;
    }
    map.Init();
}

// Move projectile and draw explosions
void Game::Update()
{
    for (int i = 0; i < 2; ++i)
    {
        player[i].projectile.Update();
        CheckCollision(i);
    }
    explosions.Draw();
    if (GetFPS() < 50)
    {
        explosions.CleanUp();
    }
}

// Check collision between player, map and projectile
void Game::CheckCollision(int i)
{
    bool playerHit = CheckCollisionCircleRec(player[i].projectile.position, player[i].projectile.projectileRadius, player[(i + 1) % 2].GetRect());
    bool selfHit = CheckCollisionCircleRec(player[i].projectile.position, player[i].projectile.projectileRadius + 20, player[i].GetRect());
    bool mapImpact = CheckCollisionCircleRec(player[i].projectile.position, player[i].projectile.projectileRadius, map.mapShape);
    bool outOfMap = (player[i].projectile.position.x < 0 || player[i].projectile.position.x > GetScreenWidth() || player[i].projectile.position.y > GetScreenHeight() || player[i].projectile.position.y < 0);
    bool explosionCollision = CheckCollisionCircles(player[i].projectile.position, player[i].projectile.projectileRadius, explosions.position, 20);

    // Map impact
    /*if (explosionCollision) {
        
    }
    else */ if (mapImpact)
    {
        player[i].projectile.active = false;
        DrawText("Impact", GetScreenWidth() / 2 - MeasureText("Impact", 20) / 2, GetScreenHeight() / 2, 20, RED);
        if (!selfHit)
        {
            explosions.AddExplosion(player[i].projectile.position);
        }
        //if (!selfHit) player[i].projectile.Explosion();
    }

    // Player impact
    if ((playerHit && player[i].projectile.active) || (playerHit && mapImpact))
    {
        player[(i + 1) % 2].health -= 20;
        player[i].projectile.active = false;
        DrawText("Impact", GetScreenWidth() / 2 - MeasureText("Impact", 20) / 2, GetScreenHeight() / 2, 20, RED);
    }

    // Out of map
    if (outOfMap)
    {
        player[i].projectile.active = false;
    }
}

// Handle input for whole instance
void Game::HandleInput()
{
    if (IsKeyPressed(KEY_P))
    {
        pause = !pause;
    }
    if (!gameStart && IsKeyPressed(KEY_ENTER))
    {
        gameStart = true;
    }
    if (GameOver() && IsKeyPressed(KEY_ENTER))
    {
        Restart();
    }
}

// Main game loop, iterate through rounds and check for game over
void Game::Rounds()
{
    // Each Player has a turn with a set amount of moves and a shot
    Player& currentPlayerRef = player[currentPlayer];
    Player& nextPlayerRef = player[(currentPlayer + 1) % 2];

    if (!pause && !GameOver() && !nextPlayerRef.projectile.active)
    {
        currentPlayerRef.playerTurn = true;
        currentPlayerRef.TakeAim();
        if (currentPlayerRef.moves > 0)
        {
            if (currentPlayerRef.Move())
            {
                currentPlayerRef.moves--;
                moves = currentPlayerRef.moves; 
            }
        }
        // Parse data to projectile and make it move
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            // Parse data to projectile
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

// Return true if game is over
bool Game::GameOver()
{
    if (player[0].health <= 0 || player[1].health <= 0)
    {
        return true;
    } else
    {
        return false;
    }
}

// Restart game and reinit variables
void Game::Restart() {
    for (int i = 0; i < 2; i++)
    {
        player[i].health = 100;
        player[i].isInit = false;
        player[i].projectile.active = false;
    }
    currentPlayer = 0;
    round = 0;
    explosions.ClearExplosions();
}