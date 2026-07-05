#include <QApplication>
#include "gui.h"

#ifdef Q_OS_WIN
#include <QtGlobal>
#endif

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GameWindow window;
    window.show();
    return app.exec();
}