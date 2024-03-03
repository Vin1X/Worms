#include "raylib.h"
#include "impact.hpp"

Impact::Impact() {}

Impact::~Impact() {}

void Impact::explosion(Vector2 position) {
    DrawCircle(position.x, position.y, 25, RAYWHITE);
}

