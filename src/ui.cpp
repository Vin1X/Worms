#include "ui.hpp"
#include <iostream>
#include <string>

Ui::Ui(int screenWidth, int screenHeight) : screenWidth(screenWidth), screenHeight(screenHeight)
{
}

Ui::~Ui() {}

// Start screen
void Ui::Init()
{
    ClearBackground(RAYWHITE);
    DrawText("NOT WORMS!", screenCenter.x - MeasureText("NOT WORMS!", 40) / 2, screenCenter.y - 20, 40, DARKGRAY);
    DrawText("PRESS [ENTER] TO START", screenCenter.x - MeasureText("PRESS [ENTER] TO START", 20) / 2, screenCenter.y + 20, 20, DARKGRAY);
}

// Draw base ui for game
void Ui::Rounds(int currentRound, int remainingMoves)
{
    std::string round = "Round: " + std::to_string(currentRound);
    std::string moves = "Moves: " + std::to_string(remainingMoves);
    DrawText(round.c_str(), screenCenter.x - MeasureText(round.c_str(), 30) / 2, 10, 30, DARKGRAY);
    DrawText(moves.c_str(), 10, 10, 20, DARKGRAY);
}

// Play sounds
void Ui::SoundPlay(SoundType sound)
{
    Sound soundToBePlayed;
    switch (sound)
    {
    case SHOT:
        soundToBePlayed = shot;
        break;
    case EXPLOSION:
        soundToBePlayed = explosion;
        break;
    default:
        break;
    }
    SetSoundVolume(soundToBePlayed, 0.1);
    PlaySound(soundToBePlayed);
}

// Draw pause screen
void Ui::Pause()
{
    DrawText("GAME PAUSED", screenCenter.x - MeasureText("GAME PAUSED", 40) / 2, screenCenter.y - 40, 40, DARKGRAY);
}

// Draw game over screen
void Ui::GameOver()
{
    ClearBackground(RAYWHITE);
    DrawText("GAME OVER", screenCenter.x - MeasureText("GAME OVER", 40) / 2, screenCenter.y - 20, 40, DARKGRAY);
    DrawText("PRESS [ENTER] TO RESTART", screenCenter.x - MeasureText("PRESS [ENTER] TO RESTART", 20) / 2, screenCenter.y + 20, 20, DARKGRAY);
}
