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

        void Init();
        void Update();
        void HandleInput();
        void Rounds();
        bool GameOver();
        Game();
        ~Game();


    private:
        Map map;
        Player player;
        Player player2;
        Projectile projectile;
        Projectile projectile2;
        //Player player[2];
};