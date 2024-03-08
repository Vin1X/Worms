#include "raylib.h"
#include "map.hpp"

Map::Map() {}

Map::~Map() {}

void Map::Init() {
    DrawRectangleRec(mapShape, color);
    ClearBackground(RAYWHITE);
}
