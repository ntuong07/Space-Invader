#include "sound.h"
#include <QSoundEffect>
#include <QUrl>
#include <QCoreApplication>

static QSoundEffect* shootSound = nullptr;
static QSoundEffect* explosionSound = nullptr;
static QSoundEffect* gameOverSound = nullptr;

// KHỞI TẠO ÂM THANH
void initSound()
{
    QString appDir = QCoreApplication::applicationDirPath();

    //Khởi tạo và nạp âm thanh bắn
    if (!shootSound) {
        shootSound = new QSoundEffect(QCoreApplication::instance());
        shootSound->setSource(QUrl::fromLocalFile(appDir + "/sounds/shoot.wav"));
        shootSound->setVolume(0.6);
        shootSound->setLoopCount(1);
    }

    //Khởi tạo và nạp âm thanh nổ
    if (!explosionSound) {
        explosionSound = new QSoundEffect(QCoreApplication::instance());
        explosionSound->setSource(QUrl::fromLocalFile(appDir + "/sounds/explosion.wav"));
        explosionSound->setVolume(0.7);
        explosionSound->setLoopCount(1);
    }

    //Khởi tạo và nạp âm thanh Game Over
    if (!gameOverSound) {
        gameOverSound = new QSoundEffect(QCoreApplication::instance());
        gameOverSound->setSource(QUrl::fromLocalFile(appDir + "/sounds/gameover.wav"));
        gameOverSound->setVolume(0.8);
        gameOverSound->setLoopCount(1);
    }
}

//HÀM PHÁT ÂM THANH
void playShootSound()
{
    if (shootSound) {
        if (shootSound->isPlaying()) {
            shootSound->stop();
        }
        shootSound->play();
    }
}

void playExplosionSound()
{
    if (explosionSound) {
        if (explosionSound->isPlaying()) {
            explosionSound->stop();
        }
        explosionSound->play();
    }
}

void playGameOverSound()
{
    if (gameOverSound) {
        if (gameOverSound->isPlaying()) {
            gameOverSound->stop();
        }
        gameOverSound->play();
    }
}