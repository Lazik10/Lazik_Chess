#include <QApplication>
#include <QtWidgets>

#include "window.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    //QWidget window;
    //window.show();
    //window.setWindowTitle("Lazik's Chess");
    //window.showFullScreen();

    ChessWindow chessWindow;
    if (!chessWindow.Initialize())
        qDebug() << "Chess Window failed to initialize";

    return app.exec();
}