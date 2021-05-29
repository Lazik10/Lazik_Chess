#include <QApplication>
#include <QtWidgets>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.show();
    window.setWindowTitle("Lazik's Chess");
    //window.showFullScreen();

    return app.exec();
}