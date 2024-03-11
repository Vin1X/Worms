#pragma once
#include "raylib.h"
#include "player.hpp"
#include "map.hpp"
#include "projectile.hpp"

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
        Projectile projectile[2];
        Player player[2];
};
