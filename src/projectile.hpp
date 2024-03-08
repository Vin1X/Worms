#pragma once
#include "raylib.h"

class Projectile {
    public:
        float projectileRadius;
        bool active;
        Vector2 target;
        Vector2 position;
        Vector2 velocity;

        Projectile();
        ~Projectile();

        void Update();
        void Init();
        void Explosion();
    private:
};
