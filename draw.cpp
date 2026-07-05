#include "draw.h"

#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "file.h"

#include <QBrush>
#include <QFont>
#include <QPen>

void drawBackground(QPainter &painter)
{
    //Tô màu nền
    painter.fillRect(0, 0, 800, 600, QColor(10, 10, 25));

    painter.setPen(Qt::NoPen);

    //Vẽ các ngôi sao
    painter.setBrush(QColor(240, 240, 255));
    for (int i = 0; i < 35; i++)
    {
        int x = (i * 137) % 800;
        int y = (i * 73) % 600;
        painter.drawRect(x, y, 3, 3);
    }

    //Vẽ các tiểu hành tinh
    const int pSize = 2;

    //Hỏa tinh đỏ
    int p1X = 150;
    int p1Y = 120;
    const int planetRed[8][8] = {
        {0,0,1,1,1,1,0,0},
        {0,1,1,2,1,1,1,0},
        {1,1,2,2,1,1,1,1},
        {1,1,2,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {0,1,1,1,1,1,1,0},
        {0,0,1,1,1,1,0,0}
    };
    for(int r=0; r<8; r++) {
        for(int c=0; c<8; c++) {
            if(planetRed[r][c] == 1) {
                painter.setBrush(QColor(180, 50, 50));
                painter.drawRect(p1X + c*pSize, p1Y + r*pSize, pSize, pSize);
            } else if(planetRed[r][c] == 2) {
                painter.setBrush(QColor(230, 100, 100));
                painter.drawRect(p1X + c*pSize, p1Y + r*pSize, pSize, pSize);
            }
        }
    }

    //Mộc tinh vàng
    int p2X = 600;
    int p2Y = 250;
    const int planetYellow[6][6] = {
        {0,0,1,1,0,0},
        {0,1,1,1,1,0},
        {1,1,1,1,1,1},
        {1,1,1,1,1,1},
        {0,1,1,1,1,0},
        {0,0,1,1,0,0}
    };
    // Vẽ vành đai
    painter.setBrush(QColor(230, 170, 70));
    painter.drawRect(p2X - 4, p2Y + 5, 20, 2);

    // Vẽ thân hành tinh
    painter.setBrush(QColor(190, 130, 50));
    for(int r=0; r<6; r++) {
        for(int c=0; c<6; c++) {
            if(planetYellow[r][c] == 1) {
                painter.drawRect(p2X + c*pSize, p2Y + r*pSize, pSize, pSize);
            }
        }
    }

    //Thủy tinh xanh
    int p3X = 280;
    int p3Y = 450;
    const int planetGreen[4][4] = {
        {0,1,1,0},
        {1,1,1,1},
        {1,1,1,1},
        {0,1,1,0}
    };
    painter.setBrush(QColor(50, 120, 90));
    for(int r=0; r<4; r++) {
        for(int c=0; c<4; c++) {
            if(planetGreen[r][c] == 1) {
                painter.drawRect(p3X + c*pSize, p3Y + r*pSize, pSize, pSize);
            }
        }
    }
}

void drawPlayer(QPainter &painter)
{
    if (playerImmunityTimer > 0)
    {
        if ((playerImmunityTimer % 8) < 4)
        {
            return;
        }
    }
    painter.setPen(Qt::NoPen);

    const int pixelSize = 4;

    const int sprite[12][12] = {
        {0,0,0,0,0,1,1,0,0,0,0,0},
        {0,0,0,0,1,3,3,1,0,0,0,0},
        {0,0,0,0,1,3,3,1,0,0,0,0},
        {0,0,0,1,2,1,1,2,1,0,0,0},
        {0,0,0,1,2,1,1,2,1,0,0,0},
        {0,1,1,1,1,1,1,1,1,1,1,0},
        {1,2,2,1,2,2,2,2,1,2,2,1},
        {1,2,2,1,1,1,1,1,1,2,2,1},
        {1,1,1,1,0,0,0,0,1,1,1,1},
        {0,1,1,0,0,0,0,0,0,1,1,0},
        {0,0,0,0,4,0,0,4,0,0,0,0},
        {0,0,0,4,4,0,0,4,4,0,0,0}
    };

    QColor color1(29, 78, 216);
    QColor color2(56, 189, 248);
    QColor color3(250, 204, 21);
    QColor color4(239, 68, 68);

    for (int row = 0; row < 12; ++row) {
        for (int col = 0; col < 12; ++col) {
            int colorType = sprite[row][col];
            if (colorType == 0) continue;

            switch (colorType) {
            case 1: painter.setBrush(color1); break;
            case 2: painter.setBrush(color2); break;
            case 3: painter.setBrush(color3); break;
            case 4: painter.setBrush(color4); break;
            }

            int xPos = playerX + (col * pixelSize);
            int yPos = playerY + (row * pixelSize);

            painter.drawRect(xPos, yPos, pixelSize, pixelSize);
        }
    }
}

void drawHUD(QPainter &painter)
{
    painter.setPen(Qt::white);

    painter.setFont(QFont("Arial", 12, QFont::Bold));

    painter.drawText(
        10,
        25,
        QString("Score: %1").arg(score)
        );

    painter.drawText(
        10,
        50,
        QString("Lives: %1").arg(lives)
        );

    painter.drawText(
        10,
        75,
        QString("Level: %1").arg(level)
        );

    painter.setPen(QColor(250, 204, 21));
    painter.drawText(
        650,
        25,
        QString("HighScore: %1").arg(highScore)
        );
}