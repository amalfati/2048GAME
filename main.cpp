#include "Widget.h"
#include <QApplication>


int main(int argc,char** argv)
{
    QApplication app(argc,argv);

    Widget Game;
    Game.setFixedSize(580,980);
    Game.setWindowTitle("2048 Game");
    Game.setWindowIcon(QIcon(":/2048.icon.PNG"));
    Game.show();

    return app.exec();
}
