#include "raylib.h"
#include "player.hpp"
#include <iostream>

Player::Player(Vector2 startPos) {
    position = startPos;
    health = 100;
}

Player::~Player() {}

Vector2 Player::move() {
    if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) position.x += 10;
    else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) position.x -= 10;
    return position;
} 

void Player::init() {
    DrawRectangleV(position, {15, 50}, BROWN);
    displayHealth();
}

void Player::displayHealth() {
    DrawText("Health: ", position.x - 40, position.y - 20, 20, BLACK);
    DrawText(std::to_string(health).c_str(), position.x + 40, position.y - 20, 20, BLACK);
}

void Player::takeAim() {
    aimingPoint = GetMousePosition();
    DrawTriangle(
        {position.x + 5, position.y + 20},
        {position.x + 10, position.y + 30},
        aimingPoint,
        LIGHTGRAY
    );
}


