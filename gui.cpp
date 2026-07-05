#include "gui.h"

#include "draw.h"
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "collision.h"
#include "file.h"
#include "sound.h"

#include <QPainter>
#include <QKeyEvent>
#include <QFont>

GameWindow::GameWindow(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(800,600);

    gameStarted = false;
    gamePaused = false;
    gameOver = false;
    bulletCooldown = 0;

    initPlayer();
    initBullets();
    initEnemies();

    timer = new QTimer(this);

    connect(timer,
            &QTimer::timeout,
            this,
            &GameWindow::updateGame);

    timer->start(16);

    initSound();
    loadHighScore();
}

void GameWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // Background
    drawBackground(painter);

    // MENU START
    if(!gameStarted)
    {
        painter.setPen(Qt::white);

        painter.setFont(QFont("Arial",28,QFont::Bold));

        painter.drawText(rect(),
                         Qt::AlignCenter,
                         "SPACE INVADER");

        painter.setFont(QFont("Arial",14));

        painter.drawText(0,
                         360,
                         width(),
                         40,
                         Qt::AlignCenter,
                         "Press ENTER to Start");

        painter.drawText(0,
                         390,
                         width(),
                         40,
                         Qt::AlignCenter,
                         "Move : Left / Right");

        painter.drawText(0,
                         420,
                         width(),
                         40,
                         Qt::AlignCenter,
                         "Shoot : SPACE (Hold to Fire)");

        painter.drawText(0,
                         450,
                         width(),
                         40,
                         Qt::AlignCenter,
                         "Pause : P");

        return;
    }

    // Gameplay
    drawEnemies(painter);

    drawBullets(painter);

    drawPlayer(painter);

    drawHUD(painter);

    // Pause
    if(gamePaused && !gameOver)
    {
        painter.setPen(Qt::yellow);

        painter.setFont(QFont("Arial",24,QFont::Bold));

        painter.drawText(rect(),
                         Qt::AlignCenter,
                         "PAUSED");
    }

    // Game Over
    if(gameOver)
    {
        painter.setPen(Qt::red);

        painter.setFont(QFont("Arial",28,QFont::Bold));

        painter.drawText(rect(),
                         Qt::AlignCenter,
                         "GAME OVER");

        painter.setFont(QFont("Arial",14));

        painter.setPen(Qt::white);

        painter.drawText(0,
                         350,
                         width(),
                         30,
                         Qt::AlignCenter,
                         QString("Final Score : %1").arg(score));

        painter.drawText(0,
                         380,
                         width(),
                         30,
                         Qt::AlignCenter,
                         "Press R to Restart");

        painter.drawText(0,
                         410,
                         width(),
                         30,
                         Qt::AlignCenter,
                         "Press ESC to Exit");
    }
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())
        return;

    // Menu Start
    if(!gameStarted)
    {
        if(event->key()==Qt::Key_Return ||
            event->key()==Qt::Key_Enter)
        {
            gameStarted=true;
        }

        return;
    }

    // Game Over
    if(gameOver)
    {
        if(event->key()==Qt::Key_R)
        {
            resetPlayer();
            initBullets();
            initEnemies();

            keysPressed.clear();
            bulletCooldown = 0;
            gameOver=false;
            gamePaused=false;

            update();
        }

        if(event->key()==Qt::Key_Escape)
        {
            close();
        }

        return;
    }

    // Pause
    if(event->key()==Qt::Key_P)
    {
        gamePaused=!gamePaused;
        if(gamePaused)
        {
            keysPressed.clear();
        }
        update();
        return;
    }

    if(gamePaused)
        return;

    //Ghi nhận phím bấm đè giữ
    keysPressed.insert(event->key());
}

void GameWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())
        return;

    keysPressed.remove(event->key());
}

void GameWindow::updateGame()
{
    // Trạng thái dừng hoặc chưa bắt đầu
    if(!gameStarted || gamePaused || gameOver)
        return;

    //Di chuyển máy bay
    if(keysPressed.contains(Qt::Key_Left))
    {
        moveLeft();
    }
    if(keysPressed.contains(Qt::Key_Right))
    {
        moveRight();
    }

    //Xử lý bắn đạn mượt
    if(bulletCooldown > 0)
    {
        bulletCooldown--;
    }

    if(keysPressed.contains(Qt::Key_Space) && bulletCooldown == 0)
    {
        shootBullet();
        bulletCooldown = 6;
    }

    //Cập nhật các thực thể vật lý
    moveBullets();

    moveEnemies();

    spawnEnemies();

    checkCollision();

    updatePlayer();

    // Kiểm tra kết thúc game
    if(lives<=0)
    {
        gameOver=true;
        keysPressed.clear();
        playGameOverSound();
        saveHighScore(highScore);
    }

    update();
}