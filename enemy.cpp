#include "enemy.h"
#include <QBrush>
#include <QPen>
#include <cstdlib>
#include <ctime>

int enemyX[MAX_ENEMIES];
int enemyY[MAX_ENEMIES];
bool enemyAlive[MAX_ENEMIES];
int enemySpeeds[MAX_ENEMIES];
int currentMaxSpeed = 1;

int enemyExplodeTimer[MAX_ENEMIES];

int enemyWidth = 32;
int enemyHeight = 32;

void initEnemies()
{
    srand((unsigned)time(nullptr));
    currentMaxSpeed = 1;

    for(int i = 0; i < MAX_ENEMIES; i++)
    {
        enemyAlive[i] = true;
        enemyX[i] = rand() % (800 - enemyWidth);
        enemyY[i] = -(rand() % 600 + 100);
        enemySpeeds[i] = currentMaxSpeed;
        enemyExplodeTimer[i] = 0;
    }
}

void spawnEnemies()
{
    for(int i = 0; i < MAX_ENEMIES; i++)
    {
        if(!enemyAlive[i] && enemyExplodeTimer[i] == 0)
        {
            if((rand() % 50) == 0)
            {
                enemyAlive[i] = true;
                enemyX[i] = rand() % (800 - enemyWidth);
                enemyY[i] = -(rand() % 150 + 50);
                enemySpeeds[i] = currentMaxSpeed;
            }
        }
    }
}

void moveEnemies()
{
    for(int i = 0; i < MAX_ENEMIES; i++)
    {
        if (enemyExplodeTimer[i] > 0)
        {
            enemyExplodeTimer[i]--;
            continue;
        }

        if(!enemyAlive[i])
            continue;

        enemyY[i] += enemySpeeds[i];

        if(enemyY[i] > 600)
        {
            enemyY[i] = -50;
            enemyX[i] = rand() % (800 - enemyWidth);
            enemySpeeds[i] = currentMaxSpeed;
        }
    }
}

void drawEnemies(QPainter &painter)
{
    painter.setPen(Qt::NoPen);
    const int pixelSize = 4;

    // Ma trận bọ vũ trụ gố
    const int enemySprite[8][8] = {
        {0,1,0,0,0,0,1,0},
        {0,0,1,0,0,1,0,0},
        {0,1,1,1,1,1,1,0},
        {1,1,2,1,1,2,1,1},
        {1,1,1,1,1,1,1,1},
        {1,0,3,1,1,3,0,1},
        {1,0,1,0,0,1,0,1},
        {0,1,0,0,0,0,1,0}
    };

    QColor bodyColor(168, 85, 247);
    QColor eyeColor(239, 68, 68);
    QColor accentColor(244, 114, 182);

    for(int i = 0; i < MAX_ENEMIES; i++)
    {
        //Enemy đang dính đạn và nổ
        if (enemyExplodeTimer[i] > 0)
        {
            if (enemyExplodeTimer[i] > 10)
                painter.setBrush(QColor(251, 146, 60));
            else if (enemyExplodeTimer[i] > 5)
                painter.setBrush(QColor(239, 68, 68));
            else
                painter.setBrush(QColor(253, 224, 71));

            int expand = (15 - enemyExplodeTimer[i]) * 2;

            // Tâm của con quái
            int centerX = enemyX[i] + enemyWidth / 2;
            int centerY = enemyY[i] + enemyHeight / 2;

            painter.drawRect(centerX - expand, centerY - expand, 5, 5);
            painter.drawRect(centerX + expand, centerY - expand, 4, 4);
            painter.drawRect(centerX - expand, centerY + expand, 4, 4);
            painter.drawRect(centerX + expand, centerY + expand, 5, 5);

            painter.drawRect(centerX, centerY - expand, 4, 4);
            painter.drawRect(centerX, centerY + expand, 4, 4);
            painter.drawRect(centerX - expand, centerY, 4, 4);
            painter.drawRect(centerX + expand, centerY, 4, 4);

            continue;
        }

        //Enemy bình thường
        if(!enemyAlive[i])
            continue;

        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                int colorType = enemySprite[row][col];
                if (colorType == 0) continue;

                switch (colorType) {
                case 1: painter.setBrush(bodyColor); break;
                case 2: painter.setBrush(eyeColor); break;
                case 3: painter.setBrush(accentColor); break;
                }

                int xPos = enemyX[i] + (col * pixelSize);
                int yPos = enemyY[i] + (row * pixelSize);
                painter.drawRect(xPos, yPos, pixelSize, pixelSize);
            }
        }
    }
}