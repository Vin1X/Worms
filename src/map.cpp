#include "raylib.h"

class Map {
private:
    Rectangle rectangle;
    Color color;

public:

    void init() {
        DrawRectangleRec(rectangle, color);
    }

    Map(Rectangle rect, Color col) {
        rectangle = rect;
        color = col;
    }
};