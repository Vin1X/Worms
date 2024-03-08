#pragma once
#include "raylib.h"
#include "projectile.hpp"

class Player {
    public:
        Rectangle mapShape = {0, 600, 1280, 250};
        Vector2 aimingPoint;
        Vector2 position;
        Vector2 velocity;
        int health = 100;
        bool playerTurn = false;

        Player();
        ~Player();

        Vector2 Move();
        Vector2 TakeAim();
        Rectangle GetRect();
        void Init(int player, bool gameStart);
        void DisplayHealth();
        
    private:
        //Texture2D image;
        bool isInit = false;
        Projectile projectile;
};
