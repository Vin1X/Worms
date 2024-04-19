#pragma once
#include <raylib.h>
#include "player.hpp"
#include "map.hpp"
#include "ui.hpp"

class Game
{
public:
    // Variables
    int gameState = 0;
    int moves = 5;
    int round = 0;

    // Con-/Destructor
    Game(Ui &ui);
    ~Game();

    // Functions
    void Restart();
    void Init();
    void Update();
    void HandleInput();
    void Rounds();
    void CheckCollision(int i);
    void GameOver();

private:
    // Variables
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
};
