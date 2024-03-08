#pragma once
#include "raylib.h"
#include "player.hpp"
#include "map.hpp"
#include "projectile.hpp"

class Game {
    public:
        int remainingMoves = 5;
        int shots = 1;
        int round = 0;
        int currentPlayer = 1;
        bool pause = false;
        bool gameStart = false;

        Game();
        ~Game();

        void Init();
        void Update();
        void HandleInput();
        void Rounds();
        bool GameOver();

    private:
        Map map;
        Projectile projectile[2];
        Player player[2];
};
