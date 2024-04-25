#include "gamescene.h"

GameScene::GameScene(QObject *parent) : QGraphicsScene(parent)
{
    // Create player block
    playerBlock = new PlayerBlock(this);
    addItem(playerBlock);
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
