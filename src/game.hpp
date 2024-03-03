#pragma once
#include "raylib.h"
#include "player.hpp"
#include "map.hpp"
#include "projectile.hpp"

class Game {
    public:
        int remainingMoves = 1;
        int shots = 2;
        int round = 3;
        int currentPlayer = 1;
        bool pause = false;
        bool gameStart = false;

        void Init();
        void Update();
        void HandleInput();
        void Rounds();
        Game();
        ~Game();


    private:
        Map map;
        Player player;
        Player player2;
        Projectile projectile;
        Projectile projectile2;
};