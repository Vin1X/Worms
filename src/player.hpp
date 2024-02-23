#pragma once
#include "raylib.h"

class Player {
    public:
        Vector2 aimingPoint;
        Vector2 position;
        int health;

        void takeAim();
        Vector2 move();
        void init();
        void displayHealth();
        
        Player(Vector2 startPos);
        ~Player();
        
    private:

};