#pragma once
#include <raylib.h>
#include "projectile.hpp"

class Player
{
public:
    // Variables
    int health = 100;
    int moves = 5;
    int moveLength = 10;
    bool playerTurn = false;
    Vector2 aimingPoint;
    Vector2 position;
    Vector2 velocity;
    Vector2 origin;
    Rectangle destRec;

    // Con-/Destructor
    Player();
    ~Player();

    // Functions
    bool Move();
    void Init(int player);
    void DisplayHealth();
    Vector2 TakeAim();
    Rectangle GetRect();

    // Projectile class
    Projectile projectile;

private:
    // Variables
    Rectangle mapShape = {0, 600, 1280, 250};

    // Playermodel
    Texture2D playermodel = LoadTexture("resources/img/idle.png");
    float playerScale = 1.5f;
    Rectangle sourceRec = {0.0f, 0.0f, (float)playermodel.width, (float)playermodel.height};

    // Aiming
    Vector2 direction;
    float distance;
    float speed;
    float angle;
};
