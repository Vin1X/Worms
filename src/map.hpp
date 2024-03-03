#pragma once
#include "raylib.h"

class Map {
    public:
        Rectangle mapShape = {0, 600, 1280, 250};
        Color color = BLACK;
        void Init();
        void Explosion(Vector2 position);
        
        Map();
        ~Map();

    private:

};