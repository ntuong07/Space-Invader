#include "file.h"
#include <fstream>

using namespace std;

int highScore = 0;

int loadHighScore()
{
    ifstream file("highscore.txt");

    if (!file.is_open())
    {
        highScore = 0;
        return highScore;
    }

    file >> highScore;
    file.close();

    return highScore;
}

void saveHighScore(int score)
{
    ofstream file("highscore.txt");

    if (!file.is_open())
        return;

    file << score;
    file.close();
}

void updateHighScore(int score)
{
    if (score > highScore)
    {
        highScore = score;
        saveHighScore(highScore);
    }
}