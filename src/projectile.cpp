#include "raylib.h"
#include "projectile.hpp"
#include <iostream>

Projectile::Projectile(Vector2 playerPosition) {
    position = playerPosition;
}

Projectile::~Projectile() {}

void Projectile::update() {
    Vector2 velocity = {5, 1};
    if (active) {
        position.x += velocity.x;
        position.y += velocity.y;
    
        if (position.x >= GetScreenWidth() || position.x <= 0 || 
            position.y >= GetScreenHeight() || position.y <= 0) {
            active = false;
        }
    }
}

void Projectile::init() {
    projectileRadius = 5;
    if (active) DrawCircleV(position, projectileRadius, RED);
}

// Try to implement the shoot method here not in main.cpp
void Projectile::shoot() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        init();
        update();
        active = true;
    }
}
