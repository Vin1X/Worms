#pragma once
#include "raylib.h"

#include <string>

class Ui {
    public:
        int screenWidth = 1280;
        int screenHeight = 720;

        Ui();
        ~Ui();
        void Init();
        void Rounds(int remainingRounds, int remainingMoves, int remainingShots);
        void Pause();
        void GameOver();
        

    private:
        Vector2 screenCenter = {screenWidth / 2, screenHeight / 2};
};