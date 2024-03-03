#pragma once
#include "raylib.h"

class Projectile {
    public:
        Vector2 target;
        Vector2 position;
        Vector2 velocity;
        float projectileRadius;
        bool active;

        Projectile();
        ~Projectile();

        void Update();
        void Init();
        void Impact();
        //void shoot();
    private:
};