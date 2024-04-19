#pragma once
#include <raylib.h>
#include "player.hpp"
#include "map.hpp"
#include "ui.hpp"

class Game
{
public:
    // Con-/Destructor
    Game(Ui &ui);
    ~Game();

    // Functions
    void Init();
    void Rounds();
    void Update();
    void HandleInput();

private:
    // Variables
    int gameState = 0;
    int moves = 5;
    int round = 0;
    int playerNumber = 1;
    int currentPlayer = 0;
    bool playerHit;
    bool selfHit;
    bool mapImpact;
    bool outOfMap;

    // Classes
    Map map;
    Player player[2];
    Explosions explosions;
    Ui &ui;

    // Functions
    void CheckCollision(int i);
    void GameOver();
    void Restart();
};
