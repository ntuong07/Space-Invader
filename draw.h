#ifndef DRAW_H
#define DRAW_H

#include <QPainter>

// Hàm cấu hình ma trận sao tự nhiên
void initBackgroundStars();

void drawBackground(QPainter &painter);
void drawPlayer(QPainter &painter);
void drawHUD(QPainter &painter);
void drawEnemies(QPainter &painter);
void drawBullets(QPainter &painter);

#endif