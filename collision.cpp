#include "collision.h"
#include "bullet.h"
#include "enemy.h"
#include "player.h"
#include "utils.h"
#include "sound.h"
#include "file.h"

void checkCollision()
{
    // Đạn trúng quái
    for(int i = 0; i < MAX_BULLETS; i++)
    {
        if(!bulletActive[i])
            continue;

        for(int j = 0; j < MAX_ENEMIES; j++)
        {
            if(!enemyAlive[j] || enemyExplodeTimer[j] > 0)
                continue;

            if(checkOverlap(bulletX[i], bulletY[i], bulletWidth, bulletHeight,
                             enemyX[j], enemyY[j], enemyWidth, enemyHeight))
            {
                bulletActive[i] = false;
                enemyAlive[j] = false;
                enemyExplodeTimer[j] = 15;

                playExplosionSound();

                score += 10;

                if (score > highScore)
                {
                    highScore = score;
                }

                if(score > 0 && score % 200 == 0)
                {
                    level++;
                    if(currentMaxSpeed < 8)
                    {
                        currentMaxSpeed++;
                    }
                }
                break;
            }
        }
    }

    // Quái đụng người
    for(int i = 0; i < MAX_ENEMIES; i++)
    {
        if(!enemyAlive[i])
            continue;

        if(checkOverlap(playerX, playerY, playerWidth, playerHeight,
                         enemyX[i], enemyY[i], enemyWidth, enemyHeight))
        {
            if(playerImmunityTimer == 0)
            {
                enemyAlive[i] = false;
                lives--;

                if(lives < 0)
                    lives = 0;

                playerImmunityTimer = 60;
            }
        }
    }
}