#pragma once
#include <raylib.h>
#include "projectile.hpp"

class Player {
    public:
        int health = 100;
        int moves = 5;
        bool isInit = false;
        bool playerTurn = false;
        Vector2 aimingPoint;
        Vector2 position;
        Vector2 velocity;
        Vector2 origin;

        Player();
        ~Player();

        bool Move();
        void Init(int player);
        void DisplayHealth();
        Vector2 TakeAim();
        Rectangle GetRect();

        Projectile projectile;
        
    private:
        Rectangle mapShape = {0, 600, 1280, 250};
        Texture2D playermodel;
        Vector2 direction;
        float distance;
        float speed;
        float angle;
};
