#include "raylib.h"
#include "map.hpp"

Map::Map() {}

Map::~Map() {}

void Map::Init() {
    DrawRectangleRec(mapShape, color);
    ClearBackground(RAYWHITE);
}

void Map::Explosion(Vector2 position) {
    DrawCircle(position.x, position.y, 25, RAYWHITE);
}
