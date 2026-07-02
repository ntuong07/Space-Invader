#include "player.h"

//==============================
// Kích thước máy bay
//==============================

int playerWidth = 40;
int playerHeight = 30;

//==============================
// Vị trí
//==============================

int playerX;
int playerY;

//==============================
// Tốc độ
//==============================

int playerSpeed = 8;

//==============================
// HUD
//==============================

int score;
int lives;
int level;

//==============================
// Khởi tạo
//==============================

void initPlayer()
{
    playerX = 380;
    playerY = 520;

    score = 0;
    lives = 3;
    level = 1;
}

//==============================
// Reset
//==============================

void resetPlayer()
{
    initPlayer();
}

//==============================
// Cập nhật
//==============================

void updatePlayer()
{
    // Sau này Thành viên 2 sẽ cập nhật:
    // - Va chạm
    // - Tăng điểm
    // - Lên Level
}

//==============================
// Sang trái
//==============================

void moveLeft()
{
    playerX -= playerSpeed;

    if(playerX < 0)
    {
        playerX = 0;
    }
}

//==============================
// Sang phải
//==============================

void moveRight()
{
    playerX += playerSpeed;

    if(playerX + playerWidth > 800)
    {
        playerX = 800 - playerWidth;
    }
}