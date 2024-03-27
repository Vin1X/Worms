#pragma once
#include <raylib.h>

class Projectile {
    public:
        bool active = false;
        float projectileRadius;
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
