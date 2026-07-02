#include "draw.h"
#include "player.h"

#include <QFont>
#include <QColor>
#include <QString>

//==============================
// Vẽ nền
//==============================
void drawBackground(QPainter &painter)
{
    painter.fillRect(0,0,800,600,QColor(10,10,30));

    painter.setPen(Qt::white);

    for(int i=0;i<120;i++)
    {
        int x=(i*67)%800;
        int y=(i*41)%600;

        painter.drawPoint(x,y);
    }
}

//==============================
// Vẽ máy bay
//==============================
void drawPlayer(QPainter &painter)
{
    painter.setPen(Qt::NoPen);

    // Thân
    painter.setBrush(QColor(0,180,255));
    painter.drawRoundedRect(playerX,playerY,40,25,4,4);

    // Mũi
    QPoint nose[3]=
        {
            QPoint(playerX+20,playerY-18),
            QPoint(playerX+10,playerY),
            QPoint(playerX+30,playerY)
        };

    painter.setBrush(QColor(255,80,80));
    painter.drawPolygon(nose,3);

    // Cánh trái
    QPoint leftWing[3]=
        {
            QPoint(playerX,playerY+8),
            QPoint(playerX-15,playerY+18),
            QPoint(playerX,playerY+20)
        };

    painter.setBrush(QColor(0,220,255));
    painter.drawPolygon(leftWing,3);

    // Cánh phải
    QPoint rightWing[3]=
        {
            QPoint(playerX+40,playerY+8),
            QPoint(playerX+55,playerY+18),
            QPoint(playerX+40,playerY+20)
        };

    painter.drawPolygon(rightWing,3);

    // Buồng lái
    painter.setBrush(Qt::yellow);
    painter.drawEllipse(playerX+15,playerY+5,10,10);

    // Động cơ trái
    painter.setBrush(Qt::gray);
    painter.drawRect(playerX+5,playerY+25,8,6);

    // Động cơ phải
    painter.drawRect(playerX+27,playerY+25,8,6);

    // Lửa động cơ
    painter.setBrush(Qt::red);

    painter.drawEllipse(playerX+6,playerY+31,6,8);
    painter.drawEllipse(playerX+28,playerY+31,6,8);
}

//==============================
// HUD
//==============================
void drawHUD(QPainter &painter)
{
    painter.setPen(Qt::white);

    painter.setFont(QFont("Arial",12,QFont::Bold));

    painter.drawText(20,30,
                     QString("Score : %1").arg(score));

    painter.drawText(20,55,
                     QString("Lives : %1").arg(lives));

    painter.drawText(20,80,
                     QString("Level : %1").arg(level));
}

//==============================
// Start Menu
//==============================
void drawStartScreen(QPainter &painter)
{
    painter.fillRect(0,0,800,600,QColor(10,10,30));

    painter.setPen(Qt::cyan);

    painter.setFont(QFont("Arial",30,QFont::Bold));

    painter.drawText(QRect(0,80,800,50),
                     Qt::AlignCenter,
                     "SPACE INVADERS");

    painter.setPen(Qt::white);

    painter.setFont(QFont("Arial",18));

    painter.drawText(QRect(0,220,800,40),
                     Qt::AlignCenter,
                     "Press ENTER to Start");

    painter.drawText(QRect(0,260,800,40),
                     Qt::AlignCenter,
                     "Arrow Keys : Move");

    painter.drawText(QRect(0,300,800,40),
                     Qt::AlignCenter,
                     "SPACE : Shoot");

    painter.drawText(QRect(0,340,800,40),
                     Qt::AlignCenter,
                     "P : Pause");

    painter.drawText(QRect(0,380,800,40),
                     Qt::AlignCenter,
                     "ESC : Exit");
}

//==============================
// Pause
//==============================
void drawPauseScreen(QPainter &painter)
{
    painter.fillRect(0,0,800,600,QColor(0,0,0,150));

    painter.setPen(Qt::yellow);

    painter.setFont(QFont("Arial",28,QFont::Bold));

    painter.drawText(QRect(0,220,800,50),
                     Qt::AlignCenter,
                     "PAUSED");

    painter.setPen(Qt::white);

    painter.setFont(QFont("Arial",16));

    painter.drawText(QRect(0,280,800,40),
                     Qt::AlignCenter,
                     "Press P to Continue");
}

//==============================
// Game Over
//==============================
void drawGameOverScreen(QPainter &painter)
{
    painter.fillRect(0,0,800,600,QColor(0,0,0,200));

    painter.setPen(Qt::red);

    painter.setFont(QFont("Arial",34,QFont::Bold));

    painter.drawText(QRect(0,150,800,50),
                     Qt::AlignCenter,
                     "GAME OVER");

    painter.setPen(Qt::white);

    painter.setFont(QFont("Arial",18));

    painter.drawText(QRect(0,240,800,40),
                     Qt::AlignCenter,
                     QString("Final Score : %1").arg(score));

    painter.drawText(QRect(0,300,800,40),
                     Qt::AlignCenter,
                     "Press R to Restart");

    painter.drawText(QRect(0,340,800,40),
                     Qt::AlignCenter,
                     "Press ESC to Exit");
}