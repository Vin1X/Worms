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

        void Init(int player, bool gameStart);
        void DisplayHealth();
        Vector2 Move();
        Vector2 TakeAim();
        Rectangle GetRect();
        
        
    private:
        bool isInit = false;
        //Texture2D image;
};