#pragma once
#include <raylib.h>
#include "explosions.hpp"

class Map {
    public:
        Rectangle mapShape = {0, 600, 1280, 250};
        Color color = BLACK;
        
        Map();
        ~Map();
        
        void Init();

    private:
        Image background = LoadImage("img/background.jpg");
};
