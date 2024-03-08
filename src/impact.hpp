#pragma once
#include "raylib.h"

class Impact {
    public:
        Vector2 position;
        bool active;

        Impact();
        ~Impact();

        void explosion(Vector2 position);
    private:
    
};
