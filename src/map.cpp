#include <raylib.h>
#include "map.hpp"

using namespace std;

Map::Map() {

}

Map::~Map() {}

void Map::Init() {
    //ImageDraw(&background, 0, 0, RAYWHITE);
    DrawRectangleRec(mapShape, color);
    ClearBackground(RAYWHITE);
}
