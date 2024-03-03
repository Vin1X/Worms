#pragma once
#include "raylib.h"

class Player {
    public:
        Player();
        ~Player();

        Rectangle mapShape = {0, 600, 1280, 250};
        Vector2 aimingPoint;
        Vector2 position;
        Vector2 velocity;
        int health = 100;
        bool playerTurn = false;

        void Init(int player);
        void DisplayHealth();
        Vector2 Move();
        Vector2 TakeAim();
        Rectangle GetRect();
        
        
    private:
        //Texture2D image;
};