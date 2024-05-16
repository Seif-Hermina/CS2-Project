#include "enemybrick.h"
#include "GameOverWindow.h"
#include "ball.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QApplication>
#include <QGraphicsView>

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
    // Update the score and the score message

    //scene()->removeItem(scoreMsg);
    score++;
    scoreMsg->setPlainText((QString("Score: ") + QString::number(score)));
    //scene()->addItem(scoreMsg);
}

void ENEMYBRICK::decrease() {
    //scene()->removeItem(healthMsg);
    health--;
    healthMsg->setPlainText(QString("Health: ") + QString::number(health));
    //scene()->addItem(healthMsg);

    if (health <= 0) {
        GameOverWindow *gameOverWindow = new GameOverWindow();
        gameOverWindow->show();

        // Close the main game window
        QWidget *mainWindow = m_scene->views().at(0)->window();
        mainWindow->close();
    } else {
        respawnBall();
    }
}


void ENEMYBRICK::respawnBall() {
    // Find the existing ball in the scene and delete it
    foreach (QGraphicsItem *item, m_scene->items()) {
        if (Ball *ball = dynamic_cast<Ball *>(item)) {
            m_scene->removeItem(ball);
            delete ball;
            break;
        }
    }

    // Create a new ball and add it to the scene
    Ball *newBall = new Ball(m_scene);
    newBall->setPos(400, 400);
    m_scene->addItem(newBall);
    newBall->setEnemyBrick(this); // Link the new ball to the enemy brick
}
