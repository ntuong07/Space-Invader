#ifndef PLAYER_H
#define PLAYER_H

// Biến người chơi
extern int playerX;
extern int playerY;
extern int playerWidth;
extern int playerHeight;
extern int playerSpeed;

//Biến đếm thời gian bất tử
extern int playerImmunityTimer;

// HUD
extern int score;
extern int lives;
extern int level;

// Hàm
void initPlayer();
void resetPlayer();
void updatePlayer();
void moveLeft();
void moveRight();

#endif