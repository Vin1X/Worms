#pragma once
#include <raylib.h>
#include "player.hpp"
#include "map.hpp"

class Game {
    public:
        bool pause = false;
        bool gameStart = false;
        int moves = 5;
        int round = 0;

        Game();
        ~Game();

        void Restart();
        void Init();
        void Update();
        void HandleInput();
        void Rounds();
        void CheckCollision(int i);
        bool GameOver();

    private:
        int playerNumber = 1;
        int currentPlayer = 0;
        bool playerHit;
        bool selfHit;
        bool mapImpact;
        bool outOfMap;
        
        Map map;
        Player player[2];
        Explosions explosions;
};
