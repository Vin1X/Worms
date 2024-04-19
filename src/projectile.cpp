#include "raylib.h"
#include "projectile.hpp"

Projectile::Projectile() {}

Projectile::~Projectile() {}

// Update position of projectile
void Projectile::Update()
{
    // Apply gravity and speed to projectile
    float gravity = 0.2;
    if (active)
    {
        velocity.y += gravity;
        position.x += velocity.x;
        position.y += velocity.y;
    }
}

// Draw projectile
void Projectile::Draw()
{
    // We have to update the destination
    Rectangle destRec = {
        position.x,
        position.y + 5,
        projectileTexture.width * projectileScale,
        projectileTexture.height * projectileScale};

    projectileRadius = 5;

    if (active)
        DrawTexturePro(projectileTexture, sourceRec, destRec, Vector2{0, 0}, 0, WHITE);
}
