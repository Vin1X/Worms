#include "ui.hpp"
#include <iostream>
#include <string>

Ui::Ui(int screenWidth, int screenHeight) : screenWidth(screenWidth), screenHeight(screenHeight)
{
}

Ui::~Ui()
{
    UnloadMusicStream(startMusic);
    UnloadMusicStream(gameMusic);
    UnloadSound(shot);
    UnloadSound(explosion);
    UnloadSound(death);
    UnloadSound(hit);
}

// Start screen
void Ui::Init()
{
    ClearBackground(RAYWHITE);
    DrawText("NOT WORMS!", screenWidth / 2 - MeasureText("NOT WORMS!", 40) / 2, screenHeight / 2 - 20, 40, DARKGRAY);
    DrawText("PRESS [ENTER] TO START", screenWidth / 2 - MeasureText("PRESS [ENTER] TO START", 20) / 2, screenHeight / 2 + 20, 20, DARKGRAY);
}

void Ui::MusicPlay(MusicType music)
{
    Music musicToBePlayed;
    switch (music)
    {
    case START:
        musicToBePlayed = startMusic;
        break;
    case GAME:
        musicToBePlayed = gameMusic;
        break;
    default:
        break;
    }
    SetMusicVolume(musicToBePlayed, 0.1);
    PlayMusicStream(musicToBePlayed);
    UpdateMusicStream(musicToBePlayed);
}

// Draw base ui for game
void Ui::Rounds(int currentRound, int remainingMoves)
{
    std::string round = "Round: " + std::to_string(currentRound);
    std::string moves = "Moves: " + std::to_string(remainingMoves);
    DrawText(round.c_str(), screenWidth / 2 - MeasureText(round.c_str(), 30) / 2, 10, 30, DARKGRAY);
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
    case DEATH:
        soundToBePlayed = death;
        break;
    case HIT:
        soundToBePlayed = hit;
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
    DrawText("GAME PAUSED", screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2, screenHeight / 2 - 40, 40, DARKGRAY);
}

// Draw game over screen
void Ui::GameOver()
{
    ClearBackground(RAYWHITE);
    DrawText("GAME OVER", screenWidth / 2 - MeasureText("GAME OVER", 40) / 2, screenHeight / 2 - 20, 40, DARKGRAY);
    DrawText("PRESS [ENTER] TO RESTART", screenWidth / 2 - MeasureText("PRESS [ENTER] TO RESTART", 20) / 2, screenHeight / 2 + 20, 20, DARKGRAY);
}
