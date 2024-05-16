#include "game.h"
#include "playerblock.h"
#include "enemybrick.h"
#include "ball.h"
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include <QBrush>

game::game() {


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
    PlayerBlock *playerBlock = new PlayerBlock(scene);

    // Create the Ball
    Ball *ball = new Ball(scene);
    ball->setPos(400, 400); // Position the ball
    scene->addItem(ball);

    // Create the ENEMYBRICK after creating the Ball
    ENEMYBRICK *enemybrick = new ENEMYBRICK(scene);
    enemybrick->spawnEnemyBricks();

    // Assign the ENEMYBRICK to the Ball
    ball->setEnemyBrick(enemybrick);
}

