#include <raylib.h>
#include "player.hpp"
#include <iostream>
#include <math.h>

using namespace std;

// Init projectile class and get player position
Player::Player()
{
    origin = {15, 50};
    projectile = Projectile();
}

// Unload player model
Player::~Player()
{
    UnloadTexture(playermodel);
}

// Draw player with projectile and set player position
void Player::Init(int player)
{
    // We have to update the destination
    Rectangle destRec = {
        position.x,
        position.y + 5,
        playermodel.width * playerScale,
        playermodel.height * playerScale};

    if (player == 1)
    {
        position = {100, mapShape.y - playermodel.height - 25};
    }
    else if (player == 2)
    {
        position = {1180, mapShape.y - playermodel.height - 25};
        playermodel = LoadTexture("resources/img/idle2.png"); // Maniuplate playermodel based on where you aim instead of this shit
    }

    DisplayHealth();
    DrawTexturePro(playermodel, sourceRec, destRec, Vector2{0, 0}, 0, WHITE);
    projectile.Draw();
}

// Display player health
void Player::DisplayHealth()
{
    DrawText("Health: ", position.x - 35, position.y - 20, 20, BLACK);
    DrawText(to_string(health).c_str(), position.x + 45, position.y - 20, 20, BLACK);
}

// Move player and return true if key is pressed for game logic
bool Player::Move()
{
    if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
    {
        if (position.x + origin.x < GetScreenWidth())
        {
            position.x += moveLength;
        }
        else
        {
            position.x = GetScreenWidth() - origin.x;
        }
        return true;
    }
    else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
    {
        if (position.x > 0)
        {
            position.x -= moveLength;
        }
        else
        {
            position.x = 0;
        }
        return true;
    }
    else
        return false;
}

// Draw aiming line
Vector2 Player::TakeAim()
{
    aimingPoint = GetMousePosition();
    DrawLineEx(
        {position.x + 15, position.y + 25},
        aimingPoint,
        5,
        LIGHTGRAY);

    // Super expert math to calculate the angle and velocity of the projectile (Ki)
    direction.x = GetMouseX() - position.x;
    direction.y = GetMouseY() - position.y;
    distance = sqrtf(direction.x * direction.x + direction.y * direction.y);
    angle = atan2f(direction.y, direction.x);
    speed = distance * 0.03;
    velocity.x = cosf(angle) * speed;
    velocity.y = sinf(angle) * speed;
    return aimingPoint;
}

// Get player rectangle for collision detection
Rectangle Player::GetRect()
{
    return {position.x, position.y, playermodel.width * playerScale, playermodel.height * playerScale};
}
