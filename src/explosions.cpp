#include <raylib.h>
#include "explosions.hpp"

Explosions::Explosions() {}

Explosions::~Explosions() {}

void Explosions::AddExplosion(Vector2 position) {
    Explosion newExplosion;
    newExplosion.position = position;
    newExplosion.active = true;
    explosion.push_back(newExplosion);
}

// Animation
void Explosions::Update() {

}

void Explosions::Draw() {
    for (const auto& explosion : explosion) {
        if (explosion.active) {
            DrawCircleV(explosion.position, 20, RAYWHITE);
        }
    }
}

void Explosions::ClearExplosions() {
    explosion.clear();
    explosionCount = 0;
}