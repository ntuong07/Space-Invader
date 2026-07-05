#ifndef ENEMY_H
#define ENEMY_H

#include <QPainter>

const int MAX_ENEMIES = 8;

// Vị trí
extern int enemyX[MAX_ENEMIES];
extern int enemyY[MAX_ENEMIES];

// Trạng thái
extern bool enemyAlive[MAX_ENEMIES];

//Tốc độ riêng của từng con quái
extern int enemySpeeds[MAX_ENEMIES];

//Tốc độ chuẩn hiện tại của hệ thống
extern int currentMaxSpeed;
extern int enemyExplodeTimer[MAX_ENEMIES];

// Kích thước
extern int enemyWidth;
extern int enemyHeight;

// Hàm
void initEnemies();
void spawnEnemies();
void moveEnemies();
void drawEnemies(QPainter &painter);

#endif