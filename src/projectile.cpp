#include "raylib.h"
#include "projectile.hpp"
#include <iostream>
#include <math.h>

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

void Projectile::Impact() {
    /*/if (active) {
        if (position.x < 0 || position.x > 1280) {
            active = false;
        }
    }/*/

}
/*/ Try to implement the shoot method here not in main.cpp
void Projectile::shoot() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        init();
        update();
        active = true;
    }
}/*/

