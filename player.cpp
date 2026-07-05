#include "player.h"

// Kích thước máy bay
int playerWidth = 48;
int playerHeight = 48;

// Vị trí
int playerX;
int playerY;

// Tốc độ
int playerSpeed = 8;

// HUD
int score;
int lives;
int level;
int playerImmunityTimer = 0;

// Khởi tạo
void initPlayer()
{
    playerX = 376;
    playerY = 500;
    score = 0;
    lives = 3;
    level = 1;
    playerImmunityTimer = 0;
}

// Reset
void resetPlayer()
{
    initPlayer();
}

// Cập nhật
void updatePlayer()
{
    if (playerImmunityTimer > 0)
    {
        playerImmunityTimer--;
    }
}

// Sang trái
void moveLeft()
{
    playerX -= playerSpeed;

    if(playerX < 0)
    {
        playerX = 0;
    }
}

// Sang phải
void moveRight()
{
    playerX += playerSpeed;

    if(playerX + playerWidth > 800)
    {
        playerX = 800 - playerWidth;
    }
}