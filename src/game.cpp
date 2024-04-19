#include <raylib.h>
#include "game.hpp"

Game::Game(Ui &ui) : ui(ui)
{
    /*
    4 game states:
    start = 0
    running = 1
    pause = 2
    game over = 3
    */
}

Game::~Game() {}

// Initialize players and map
void Game::Init()
{
    ui.MusicPlay(ui.START);
    // Only display on boot
    if (gameState == 0)
    {
        ui.Init();
    }
    else if (gameState == 3)
    {
        ui.GameOver();
    }
    else
    {
        for (auto &player : player)
        {
            player.Init(playerNumber);
            playerNumber++;
        }
        map.Init();
        ui.Rounds(round, player[currentPlayer].moves); // Update Ui after player change
    }
}

// Move projectile and pause game
void Game::Update()
{
    if (gameState == 1)
    {
        for (int i = 0; i < 2; ++i)
        {
            player[i].projectile.Update();
            CheckCollision(i);
        }
    }
    else if (gameState == 2)
    {
        ui.Pause();
    }

    explosions.Draw();

    // Clean up explosions if fps drop
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
    bool outOfMap = (player[i].projectile.position.x < 0 || player[i].projectile.position.x > ui.screenWidth || player[i].projectile.position.y > ui.screenHeight || player[i].projectile.position.y < 0);

    // Map impact
    if (mapImpact)
    {
        player[i].projectile.active = false;
        if (!selfHit)
        {
            explosions.AddExplosion(player[i].projectile.position);
        }
    }

    // Player impact
    if ((playerHit && player[i].projectile.active) || (playerHit && mapImpact))
    {
        player[i].projectile.active = false;
        player[(i + 1) % 2].health -= 20;
        if (player[i + 1].health > 0)
        {
            ui.SoundPlay(ui.HIT);
        }
    }

    // Out of map
    if (outOfMap)
    {
        player[i].projectile.active = false;
    }

    GameOver();
}

// Handle input for whole instance
void Game::HandleInput()
{
    if (gameState == 2 && IsKeyPressed(KEY_P))
    {
        gameState = 1;
    }
    else if (gameState == 1 && IsKeyPressed(KEY_P))
    {
        gameState = 2;
    }
    if (gameState == 0 && IsKeyPressed(KEY_ENTER))
    {
        gameState = 1;
    }
    if (gameState == 3 && IsKeyPressed(KEY_ENTER))
    {
        Restart();
    }
}

// Main game loop, iterate through rounds and check for game over
void Game::Rounds()
{
    // Each Player has a turn with a set amount of moves and one shot
    Player &currentPlayerRef = player[currentPlayer];
    Player &nextPlayerRef = player[(currentPlayer + 1) % 2];

    if (gameState == 1 && !nextPlayerRef.projectile.active)
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
        // Shoot projectile
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            ui.SoundPlay(ui.SHOT);

            // Parse data to projectile
            currentPlayerRef.projectile.active = true;
            currentPlayerRef.projectile.position = {currentPlayerRef.position.x + 10, currentPlayerRef.position.y + 30};
            currentPlayerRef.projectile.velocity = currentPlayerRef.velocity;
            currentPlayerRef.playerTurn = false;

            // Switch player
            currentPlayer = (currentPlayer + 1) % 2;
            player[currentPlayer].moves = 5;
            player[currentPlayer].playerTurn = true;
            if (currentPlayer == 0)
                round++;
        }
    }
}

// Check for game over
void Game::GameOver()
{
    if (player[0].health <= 0 || player[1].health <= 0)
    {
        ui.SoundPlay(ui.DEATH);
        gameState = 3;
    }
}

// Restart game and reinit variables
void Game::Restart()
{
    explosions.ClearExplosions();
    explosions.CleanUp();
    for (int i = 0; i < 2; i++)
    {
        player[i].health = 100;
        player[i].moves = 5;
        player[i].projectile.active = false;
    }
    player[0].position = {100, map.mapShape.y - player[0].playermodel.height - 25};
    player[1].position = {1180, map.mapShape.y - player[1].playermodel.height - 25};
    currentPlayer = 0;
    round = 0;
    gameState = 1;
}
