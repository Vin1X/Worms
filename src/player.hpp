#pragma once
#include <raylib.h>
#include "projectile.hpp"

class Player {
    public:
        Vector2 aimingPoint;
        Vector2 position;
        Vector2 velocity;
        Vector2 origin;
        int health = 100;
        int moves = 5;
        bool playerTurn = false;

        Player();
        ~Player();

        bool Move();
        Vector2 TakeAim();
        Rectangle GetRect();
        void Init(int player);
        void DisplayHealth();
        
    private:
        Rectangle mapShape = {0, 600, 1280, 250};
        Projectile projectile;

        Vector2 direction;
        float distance;
        float speed;
        float angle;

        Texture2D playermodel;
        bool isInit = false;
};
