#include <raylib.h>
#include "player.hpp"
#include <iostream>
#include <math.h>

using namespace std;

Player::Player() {
    origin = {15, 50};
    projectile = Projectile();
}

Player::~Player() {
    //UnloadTexture(playermodel);
}

void Player::Init(int player) {
    DrawFPS(50, 50);
    DrawRectangleV(position, origin, BROWN);
    DisplayHealth();

    // Set player position
    if (player == 1 && !isInit) {
        position = {100, mapShape.y - origin.y};
        isInit = true;
    }
    else if (player == 2 && !isInit) {
        position = {1180, mapShape.y - origin.y};
        isInit = true;
    }
    projectile.Init();
}

// Display player health
void Player::DisplayHealth() {
    DrawText("Health: ", position.x - 40, position.y - 20, 20, BLACK);
    DrawText(to_string(health).c_str(), position.x + 40, position.y - 20, 20, BLACK);
}

// Move player and return true if key is pressed for game logic
bool Player::Move() {
    if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {
        position.x += 10;
        return true;
    }
    else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) {
        position.x -= 10;
        return true;
    }
    else return false;
} 

// Draw aiming line
Vector2 Player::TakeAim() {
    aimingPoint = GetMousePosition();
    DrawLineEx(
        {position.x + 7, position.y + 25},
        aimingPoint,
        5,
        LIGHTGRAY
    );

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

// Get player rectangle
Rectangle Player::GetRect() {
    return {position.x, position.y, origin.x, origin.y};
}
