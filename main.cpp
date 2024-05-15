#include "playerblock.h"
#include "enemybrick.h"
#include "ball.h"
#include "game.h"
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include <QBrush>


game* Game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game = new game();

    return a.exec();
}
