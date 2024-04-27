#include "enemybrick.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QApplication>

ENEMYBRICK::ENEMYBRICK(QGraphicsScene *scene, QGraphicsItem *parent ): QGraphicsRectItem(parent), m_scene(scene) {
    setRect(0,100,160,30);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);

    score = 0;
    health = 3;

    QFont font;
    font.setPointSize(30);

    QColor color1(Qt::blue);
    scoreMsg = new QGraphicsTextItem(QString("Score: ") + QString::number(score));
    scoreMsg->setFont(font);
    scoreMsg->setDefaultTextColor(color1);
    scoreMsg->setPos(650, 10);
    m_scene->addItem(scoreMsg);

    QColor color2(Qt::red);
    healthMsg = new QGraphicsTextItem(QString("Health: ") + QString::number(health));
    healthMsg->setFont(font);
    healthMsg->setDefaultTextColor(color2);
    healthMsg->setPos(10, 10);
    font.setPointSize(72);
    m_scene->addItem(healthMsg);

    endMsg = new QGraphicsTextItem(QString("GAME OVER"));
    endMsg->setFont(font);
    endMsg->setDefaultTextColor(color2);
    endMsg->setPos(130, 150);

}

void ENEMYBRICK::spawnEnemyBricks(){
    const int rowCount = 7; // Number of colums of bricks
    const int colCount = 5; // Number of rows of bricks
    const int brickWidth = 160;
    const int brickHeight = 30;


    //Spawning rows and columns of bricks
    for (int col = 0; col<colCount; ++col) {
        for(int row = 0; row<rowCount; ++row){
            ENEMYBRICK* brick = new ENEMYBRICK(m_scene);

            //calculating position of each brick in the grid
            int x = col * brickWidth;
            int y = row * brickHeight;

            //setting the position
            brick->setPos(x,y);

            m_scene->addItem(brick);

        }
    }
}

void ENEMYBRICK::increase()
{
    scene()->removeItem(scoreMsg);
    score++;
    scoreMsg->setPlainText((QString("Score: ") + QString::number(score)));
    scene()->addItem(scoreMsg);

}

void ENEMYBRICK::decrease()
{
    scene()->removeItem(healthMsg);
    health--;
    healthMsg->setPlainText((QString("Health: ") + QString::number(health)));
    scene()->addItem(healthMsg);
    if(health < 1)
    {
        QApplication::quit();
    }
}
