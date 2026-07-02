#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QKeyEvent>

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void updateGame();

private:
    QTimer timer;

    bool gameStarted;
    bool gamePaused;
    bool gameOver;
};

#endif // GUI_H