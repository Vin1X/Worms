#pragma once
#include <raylib.h>
#include <string>

class Ui
{
public:
    // Variables
    float screenWidth = 1280;
    float screenHeight = 720;
    enum SoundType
    {
        SHOT,
        EXPLOSION
    };

    // Con-/Destructor
    Ui(int screenWidth, int screenHeight);
    ~Ui();

    // Functions
    void SoundPlay(SoundType sound);
    void Init();
    void Rounds(int currentRound, int remainingMoves);
    void Pause();
    void GameOver();

private:
    // Variables
    Vector2 screenCenter = {screenWidth / 2, screenHeight / 2};
    Sound shot = LoadSound("resources/sounds/gunshot.mp3");
    Sound explosion = LoadSound("resources/sounds/explosion.mp3");
};
