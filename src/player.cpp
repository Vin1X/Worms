#include "raylib.h"
#include "player.hpp"
#include <iostream>
#include <math.h>
#include "map.hpp"

Player::Player() {
    //image = LoadTexture("img/player.png");
}

Player::~Player() {
    //UnloadTexture(image);
}

void Player::Init(int player, bool gameStart) {
    if (player == 1 && !isInit) {
        position = {100, mapShape.y - 50};
        isInit = true;
    }
    else if (player == 2 && !isInit) {
        position = {1180, mapShape.y - 50};
        isInit = true;
    }
    //DrawTextureV(image, {200, 150}, WHITE);
    DrawRectangleV(position, {15, 50}, BROWN);
    DisplayHealth();
    
    if (playerTurn == true) {
        //Move();
        //TakeAim();
    }
}

void Player::DisplayHealth() {
    DrawText("Health: ", position.x - 40, position.y - 20, 20, BLACK);
    DrawText(std::to_string(health).c_str(), position.x + 40, position.y - 20, 20, BLACK);
}

Vector2 Player::Move() {
    if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) position.x += 10;
    else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) position.x -= 10;
    return position;
} 

Vector2 Player::TakeAim() {
    aimingPoint = GetMousePosition();
    DrawTriangle(
        {position.x + 5, position.y + 20},
        {position.x + 10, position.y + 30},
        aimingPoint,
        LIGHTGRAY
    );

    // Ki keine ahnung
    Vector2 direction;
    direction.x = GetMouseX() - position.x;
    direction.y = GetMouseY() - position.y;
    float distance = sqrtf(direction.x * direction.x + direction.y * direction.y);
    float angle = atan2f(direction.y, direction.x);
    float speed = distance * 0.04;
    velocity.x = cosf(angle) * speed;
    velocity.y = sinf(angle) * speed;
    return aimingPoint;
}

Rectangle Player::GetRect() {
    return {position.x, position.y, 15, 50};
}


