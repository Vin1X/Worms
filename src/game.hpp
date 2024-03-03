#pragma once
#include "raylib.h"
#include "player.hpp"
#include "map.hpp"
#include "projectile.hpp"

class Game {
    public:
        int remainingMoves;

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

};