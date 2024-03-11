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
        void Rounds(int currentRound, int remainingMoves);
        void Pause();
        void GameOver();

    private:
        Vector2 screenCenter = {screenWidth / 2, screenHeight / 2};
};