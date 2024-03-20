#pragma once
#include "raylib.h"
#include "player.hpp"
#include "map.hpp"

class Game {
    public:
        bool pause = false;
        bool gameStart = false;
        int moves;
        int round = 0;

        Game();
        ~Game();

        void Init();
        void Update();
        void HandleInput();
        void Rounds();
        bool GameOver();

    private:
        int currentPlayer = 0;
        Map map;
        Player player[2];
};
