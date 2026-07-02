#include "gui.h"

#include <QPainter>
#include <QApplication>

#include "draw.h"
#include "player.h"

GameWindow::GameWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Space Invaders");
    setFixedSize(800,600);

    gameStarted = false;
    gamePaused = false;
    gameOver = false;

    initPlayer();

    timer.setInterval(16);      // ~60 FPS

    connect(&timer,
            &QTimer::timeout,
            this,
            &GameWindow::updateGame);

    timer.start();
}

void GameWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //==============================
    // START MENU
    //==============================
    if(!gameStarted)
    {
        drawStartScreen(painter);
        return;
    }

    //==============================
    // GAMEPLAY
    //==============================
    drawBackground(painter);

    drawPlayer(painter);

    drawHUD(painter);

    //==============================
    // PAUSE
    //==============================
    if(gamePaused)
    {
        drawPauseScreen(painter);
    }

    //==============================
    // GAME OVER
    //==============================
    if(gameOver)
    {
        drawGameOverScreen(painter);
    }
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    //==============================
    // START GAME
    //==============================
    if(!gameStarted)
    {
        if(event->key()==Qt::Key_Return ||
            event->key()==Qt::Key_Enter)
        {
            gameStarted=true;
            update();
        }

        if(event->key()==Qt::Key_Escape)
        {
            QApplication::quit();
        }

        return;
    }

    //==============================
    // GAME OVER
    //==============================
    if(gameOver)
    {
        if(event->key()==Qt::Key_R)
        {
            resetPlayer();

            gameOver=false;
            gamePaused=false;

            update();
        }

        if(event->key()==Qt::Key_Escape)
        {
            QApplication::quit();
        }

        return;
    }

    //==============================
    // PAUSE
    //==============================
    if(event->key()==Qt::Key_P)
    {
        gamePaused=!gamePaused;

        update();

        return;
    }

    if(gamePaused)
        return;

    //==============================
    // PLAYER MOVE
    //==============================
    switch(event->key())
    {
    case Qt::Key_Left:
    case Qt::Key_A:

        moveLeft();

        break;

    case Qt::Key_Right:
    case Qt::Key_D:

        moveRight();

        break;

    case Qt::Key_Space:

        // Thành viên 2
        // shootBullet();

        break;

    default:

        break;
    }

    update();
}

void GameWindow::updateGame()
{
    if(!gameStarted)
        return;

    if(gamePaused)
        return;

    if(gameOver)
        return;

    updatePlayer();

    //---------------------------------
    // Tuan code o day
    //---------------------------------

    // moveEnemies();

    // moveBullets();

    // checkCollision();

    //---------------------------------
    // Hieu code o day
    //---------------------------------

    if(lives<=0)
    {
        gameOver=true;
    }

    update();
}