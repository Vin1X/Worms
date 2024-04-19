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
    // Textures
    Texture2D projectileTexture = LoadTexture("resources/img/projectile.png");
    float projectileScale = 0.1f;
    Rectangle sourceRec = {0.0f, 0.0f, (float)projectileTexture.width, (float)projectileTexture.height};
};
