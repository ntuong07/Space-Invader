#ifndef BULLET_H
#define BULLET_H

#include <QPainter>

const int MAX_BULLETS = 50;

// Vị trí đạn
extern int bulletX[MAX_BULLETS];
extern int bulletY[MAX_BULLETS];

// Trạng thái
extern bool bulletActive[MAX_BULLETS];

// Kích thước
extern int bulletWidth;
extern int bulletHeight;

// Tốc độ
extern int bulletSpeed;

// Hàm
void initBullets();

void shootBullet();

void moveBullets();

void drawBullets(QPainter &painter);

#endif