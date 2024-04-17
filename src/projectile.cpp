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
void Projectile::Init()
{
    projectileRadius = 5;
    if (active) DrawCircleV(position, projectileRadius, RED);
}
