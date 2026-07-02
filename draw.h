#ifndef DRAW_H
#define DRAW_H

#include <QPainter>

// Giao diện game
void drawBackground(QPainter &painter);
void drawPlayer(QPainter &painter);
void drawHUD(QPainter &painter);

// Các màn hình
void drawStartScreen(QPainter &painter);
void drawPauseScreen(QPainter &painter);
void drawGameOverScreen(QPainter &painter);

#endif