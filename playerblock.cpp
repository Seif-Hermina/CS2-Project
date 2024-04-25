#include "playerblock.h"
#include <QKeyEvent>

PlayerBlock::PlayerBlock(QObject *parent) : QObject(parent),
    width(80), height(20), speed(8)
{
    rect = QRectF(0, 0, width, height);
    xVelocity = 0;
}

QRectF PlayerBlock::getRect() const
{
    return rect;
}

void PlayerBlock::setRect(const QRectF &value)
{
    rect = value;
}

qreal PlayerBlock::getXVelocity() const
{
    return xVelocity;
}

void PlayerBlock::setXVelocity(const qreal &value)
{
    xVelocity = value;
}

void PlayerBlock::moveLeft()
{
    if (rect.left() > 0)
    {
        rect.moveLeft(rect.left() - speed);
    }
    else
    {
        emit hitWall();
    }
}

void PlayerBlock::moveRight()
{
    if (rect.right() < 800) // Assuming a fixed width of the game scene
    {
        rect.moveRight(rect.right() + speed);
    }
    else
    {
        emit hitWall();
    }
}
