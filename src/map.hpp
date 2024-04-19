#pragma once
#include <raylib.h>
#include "explosions.hpp"

class Map
{
public:
    // Variables
    Rectangle mapShape = {0, 600, 1280, 250};
    Color color = BLACK;

    // Con-/Destructor
    Map();
    ~Map();

    // Functions
    void Init();

private:
    // Variables
    Image background = LoadImage("resources/img/background.png");
};
