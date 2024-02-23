#pragma once
#include "raylib.h"

class Projectile {
    public:
        Vector2 target;
        Vector2 position;
        Vector2 velocity;
        float projectileRadius;
        bool active;

        Projectile(Vector2 playerPosition);
        ~Projectile();

        //bool shoot();
        void update();
        void init();
        void shoot();
    private:
};