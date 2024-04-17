#include <raylib.h>
#include "explosions.hpp"

Explosions::Explosions() {}

Explosions::~Explosions() {}

// Create explosion struct and push it to the vector 
void Explosions::AddExplosion(Vector2 position)
{
    Explosion newExplosion;
    newExplosion.position = position;
    newExplosion.active = true;
    explosion.push_back(newExplosion);
}

// Explosion particles
void Explosions::Update()
{

}

// Draw all explosions
void Explosions::Draw()
{
    // For loop to draw all explosions via index of explosion vector inorder to reduce the amount of structs (about 20 object until game start lagging)
    for (const auto& explosion : explosion)
    {
        if (explosion.active)
        {
            DrawCircleV(explosion.position, 20, RAYWHITE);
        }
    }
}

// Clear explosions
void Explosions::ClearExplosions()
{
    explosion.clear();
    explosionCount = 0;
}

// When performance is to bad, remove first explosion
void Explosions::CleanUp()
{
    explosion.erase(explosion.begin());
}