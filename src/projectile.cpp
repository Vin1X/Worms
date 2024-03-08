#include "raylib.h"
#include "projectile.hpp"

Projectile::Projectile() {}

Projectile::~Projectile() {}

void Projectile::Update() {
    float gravity = 0.2;
    if (active) {
        velocity.y += gravity;
        position.x += velocity.x;
        position.y += velocity.y;
    }
}

void Projectile::Init() {
    projectileRadius = 5;
    if (active) DrawCircleV(position, projectileRadius, RED);
}

void Projectile::Explosion() {
    DrawCircle(position.x, position.y, 25, RAYWHITE);
}
