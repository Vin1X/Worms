#pragma once
#include "raylib.h"

class Impact {
    public:
        Vector2 position;
        bool active;
        void explosion(Vector2 position);

        Impact();
        ~Impact();
    private:
};