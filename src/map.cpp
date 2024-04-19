#include <raylib.h>
#include "map.hpp"

Map::Map() {}

Map::~Map() {}

// Initialize map
void Map::Init()
{
    DrawRectangleRec(mapShape, color);
    ClearBackground(RAYWHITE);
}
