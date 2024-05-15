#include "ball.h"
#include "enemybrick.h"
#include "playerblock.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <QBrush>

Ball::Ball(QGraphicsScene *scene, QGraphicsItem *parent) : QGraphicsEllipseItem(parent), enemyBrick(nullptr) {
    // Set the initial position and size of the ball
    setRect(0, 0, 20, 20);
    // Set the initial velocity of the ball
    xVelocity = 7;
    yVelocity = 7;

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);

    // Move the ball every 30 milliseconds
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Ball::move);
    timer->start(30);
}

void Ball::move() {
    // Move the ball
    setPos(x() + xVelocity, y() + yVelocity);
    checkCollision();
}

void Ball::checkCollision() {
    // Check for collision with the scene boundaries
    if (x() <= 0 || x() + rect().width() >= scene()->width()) {
        xVelocity = -xVelocity; // Reverse the horizontal direction
    }
    if (y() <= 0) {
        yVelocity = -yVelocity; // Reverse the vertical direction
    }

    // Check for collision with the player
    QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);
    foreach (QGraphicsItem *item, collidingItems) {
        if (typeid(*item) == typeid(PlayerBlock)) {
            yVelocity = -yVelocity; // Reverse the vertical direction
            return;

        } else if (typeid(*item) == typeid(ENEMYBRICK)) {
            yVelocity = -yVelocity; // Reverse the vertical direction
            scene()->removeItem(item); // Remove the enemy brick

            /*
            ENEMYBRICK *enemyBrick = dynamic_cast<ENEMYBRICK*>(item);
            if (enemyBrick) {
                enemyBrick->increase();
            }
*/

            return;
        }
    }
    if (y() + rect().height() >= scene()->height()) {
        if (enemyBrick) {
            enemyBrick->decrease();
        }
    }
}

void Ball::setEnemyBrick(ENEMYBRICK *brick) {
    enemyBrick = brick;
}
