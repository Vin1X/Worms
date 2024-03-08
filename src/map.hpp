#pragma once
#include "raylib.h"

class Map {
    public:
        Rectangle mapShape = {0, 600, 1280, 250};
        Color color = BLACK;
        
        Map();
        ~Map();
        
        void Init();

    private:

};