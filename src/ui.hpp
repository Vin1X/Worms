#pragma once
#include <raylib.h>
#include <string>

class Ui
{
    public:
        // Variables
        float screenWidth = 1280;
        float screenHeight = 720;

        // Con-/Destructor
        Ui();
        ~Ui();

        // Functions
        void Init();
        void Rounds(int currentRound, int remainingMoves);
        void Pause();
        void GameOver();

    private:
        // Variables
        Vector2 screenCenter = {screenWidth / 2, screenHeight / 2};
};
