/*#include "gamescene.h"
#include "enemybrick.h"
#include "ball.h"
#include <QKeyEvent>

GameScene::GameScene(QObject *parent) : QGraphicsScene(parent)
{
    // Create player block
    playerBlock = new PlayerBlock(this);
    addItem(playerBlock);

    playerBlock->setPos(100,450);

   // Ball* ball = new Ball();
    //addItem(ball);

    score = 0;
    health = 3;

    QFont font;
    font.setPointSize(16);
    QColor color1(Qt::blue);
    scoreMsg = new QGraphicsTextItem(QString("Score: ") + QString::number(score));
    scoreMsg->setFont(font);
    scoreMsg->setDefaultTextColor(color1);
    scoreMsg->setPos(10, 40);
    addItem(scoreMsg);

    QColor color2(Qt::red);
    healthMsg = new QGraphicsTextItem(QString("Health: ") + QString::number(health));
    healthMsg->setFont(font);
    healthMsg->setDefaultTextColor(color2);
    healthMsg->setPos(10, 10);
    font.setPointSize(72);
    addItem(healthMsg);

    endMsg = new QGraphicsTextItem(QString("GAME OVER"));
    endMsg->setFont(font);
    endMsg->setDefaultTextColor(color2);
    endMsg->setPos(130, 150);



}

void GameScene::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Left:
        playerBlock->setXVelocity(-1);
        break;
    case Qt::Key_Right:
        playerBlock->setXVelocity(1);
        break;
    default:
        break;
    }
}

void GameScene::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Left:
    case Qt::Key_Right:
        playerBlock->setXVelocity(0);
        break;
    default:
        break;
    }
}

void GameScene::spawnEnemyBricks(){
    const int rowCount = 7; // Number of colums of bricks
    const int colCount = 5; // Number of rows of bricks
    const int brickWidth = 50;
    const int brickHeight = 20;


    //Spawning rows and columns of bricks
    for (int col = 0; col<colCount; ++col) {
        for(int row = 0; row<rowCount; ++row){
            ENEMYBRICK* brick = new ENEMYBRICK();

            //calculating position of each brick in the grid
            int x = col * brickWidth;
            int y = row * brickHeight;

            //setting the position
            brick->setPos(x,y);

            //adding to scene
            addItem(brick);
        }

    }
}

*/
