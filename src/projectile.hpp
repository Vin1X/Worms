#pragma once
#include <raylib.h>

class Projectile
{
public:
    // Variables
    bool active = false;
    float projectileRadius;
    Vector2 target;
    Vector2 position;
    Vector2 velocity;

    // Con-/Destructor
    Projectile();
    ~Projectile();

    // Functions
    void Update();
    void Draw();

private:
};
