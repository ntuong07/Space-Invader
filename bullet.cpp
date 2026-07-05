#include "bullet.h"
#include "player.h"
#include "sound.h"

#include <QBrush>
#include <QPen>

// Biến

int bulletX[MAX_BULLETS];
int bulletY[MAX_BULLETS];

bool bulletActive[MAX_BULLETS];

int bulletWidth = 4;
int bulletHeight = 12;

int bulletSpeed = 10;

// Khởi tạo

void initBullets()
{
    for(int i = 0; i < MAX_BULLETS; i++)
    {
        bulletActive[i] = false;
    }
}

// Bắn

void shootBullet()
{
    for(int i = 0; i < MAX_BULLETS; i++)
    {
        if(!bulletActive[i])
        {
            bulletActive[i] = true;

            bulletX[i] = playerX + (playerWidth / 2) - (bulletWidth / 2);
            bulletY[i] = playerY - bulletHeight;

            playShootSound();

            break;
        }
    }
}

// Di chuyển

void moveBullets()
{
    for(int i = 0; i < MAX_BULLETS; i++)
    {
        if(!bulletActive[i])
            continue;

        bulletY[i] -= bulletSpeed;

        if(bulletY[i] < -bulletHeight)
        {
            bulletActive[i] = false;
        }
    }
}

// Vẽ

void drawBullets(QPainter &painter)
{
    painter.setPen(Qt::NoPen);

    painter.setBrush(Qt::yellow);

    for(int i = 0; i < MAX_BULLETS; i++)
    {
        if(!bulletActive[i])
            continue;

        painter.drawRoundedRect(
            bulletX[i],
            bulletY[i],
            bulletWidth,
            bulletHeight,
            2,
            2
            );
    }
}