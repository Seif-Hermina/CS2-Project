#include "playerblock.h"
#include "enemybrick.h"
#include "ball.h"
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include <QBrush>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // *******  Create the View ********
    QGraphicsView *view=new QGraphicsView();
    view->setFixedSize(800, 600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // ******* Create the Scene ********
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);

    // *******   Assign scene to the view   ***************
    view->setScene(scene);
    view->show();

    // *******  Create the Player ********
    PlayerBlock *playerblock = new  PlayerBlock();

    // *******  Setting the foucs to the Player ********
    playerblock->setRect(10, 10, 200, 100);
    QBrush pbrush;
    pbrush.setStyle(Qt::SolidPattern);
    pbrush.setColor(Qt::blue);
    playerblock->setBrush(pbrush);

    playerblock->setFlag(QGraphicsItem::ItemIsFocusable);
    playerblock->setFocus();
    // *******  Adjust the location of the Player (middle of the screen) ********
    playerblock->setPos(view->width()/2, view->height() - 100);
    scene->addItem(playerblock);

    ENEMYBRICK *enemybrick = new ENEMYBRICK(scene);
    enemybrick->spawnEnemyBricks();

    // Create the Ball
    Ball *ball = new Ball();
    // Add ball to the scene
    scene->addItem(ball);

    // Set the initial position of the ball
    ball->setPos(400, 400); // Example position




    return a.exec();
}
