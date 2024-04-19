#pragma once
#include <raylib.h>
#include <string>

class Ui
{
public:
    // Variables
    float screenWidth;
    float screenHeight;
    enum SoundType
    {
        SHOT,
        EXPLOSION,
        DEATH,
        HIT
    };
    enum MusicType
    {
        START,
        GAME
    };

    // Con-/Destructor
    Ui(int screenWidth, int screenHeight);
    ~Ui();

    // Functions
    void MusicPlay(MusicType music);
    void SoundPlay(SoundType sound);
    void Init();
    void Rounds(int currentRound, int remainingMoves);
    void Pause();
    void GameOver();

private:
    // Variables
    Sound shot = LoadSound("resources/sounds/gunshot.mp3");
    Sound explosion = LoadSound("resources/sounds/explosion.mp3");
    Sound death = LoadSound("resources/sounds/death.wav");
    Sound hit = LoadSound("resources/sounds/hit.wav");
    Music startMusic = LoadMusicStream("resources/sounds/After the Storm.mp3");
    Music gameMusic = LoadMusicStream("resources/sounds/After the Storm.mp3");
};
