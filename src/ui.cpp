#include "ui.hpp"
#include <iostream>
#include <string>

Ui::Ui() {}

Ui::~Ui() {}


void Ui::Init() {
    ClearBackground(RAYWHITE);
    DrawText("NOT WORMS!", screenCenter.x - MeasureText("NOT WORMS!", 40) / 2, screenCenter.y - 20, 40, DARKGRAY);
    DrawText("PRESS [ENTER] TO START", screenCenter.x - MeasureText("PRESS [ENTER] TO START", 20) / 2, screenCenter.y + 20, 20, DARKGRAY);    
}

void Ui::Rounds(int remainingRounds, int remainingMoves, int remainingShots) {
    std::string round = "Round: " + std::to_string(remainingRounds);
    std::string moves = "Moves: " + std::to_string(remainingMoves);
    std::string shots = "Shots: " + std::to_string(remainingShots);
    DrawText(round.c_str(), screenCenter.x - MeasureText(round.c_str(), 30) / 2, 10, 30, DARKGRAY);
    DrawText(moves.c_str(), 10, 10, 20, DARKGRAY);
    DrawText(shots.c_str(), 10, 35, 20, DARKGRAY);
}

void Ui::Pause() {
    //DrawText("Game Paused", screenCenter.x, screenCenter.y, 40, DARKGRAY);
    DrawText("GAME PAUSED", screenCenter.x - MeasureText("GAME PAUSED", 40) / 2, screenCenter.y - 40, 40, GRAY);
}

void Ui::GameOver() {
    DrawText("GAME OVER", screenCenter.x - MeasureText("GAME OVER", 40) / 2, screenCenter.y - 10, 40, DARKGRAY);
    DrawText("PRESS [ENTER] TO RESTART", screenCenter.x - MeasureText("PRESS [ENTER] TO RESTART", 20) / 2, screenCenter.y + 10, 20, DARKGRAY);
}
