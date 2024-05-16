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
    xVelocity = 5;
    yVelocity = 5;

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
    // Check if the game is over (health is 0)
    if (enemyBrick && enemyBrick->health <= 0) {
        return; // Stop moving the ball
    }

    // Move the ball
    setPos(x() + xVelocity, y() + yVelocity);
    checkCollision();
}

void Ball::checkCollision() {
    // Check for collision with the scene boundaries
    if (x() <= 0 || x() + rect().width() >= scene()->width()) {
        xVelocity = -xVelocity; // Reverse the horizontal direction
    }
    if (y() <= 100) {  // 100 so it does not get stuck above score and lives
        yVelocity = -yVelocity; // Reverse the vertical direction
    }

    // Check for collision with the player and enemy bricks
    QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);
    foreach (QGraphicsItem *item, collidingItems) {
        if (typeid(*item) == typeid(PlayerBlock)) {
            yVelocity = -yVelocity; // Reverse the vertical direction
            return;
        } else if (typeid(*item) == typeid(ENEMYBRICK)) {
            yVelocity = -yVelocity; // Reverse the vertical direction
            // Increase the score because the ball hit an enemy brick
            if (enemyBrick) {
                enemyBrick->increase();
            }
            // Remove the enemy brick from the scene
            scene()->removeItem(item);
            delete item; // Delete the brick to free memory

            // Check if the level is complete and move to the next level
            if (enemyBrick->checkLevelComplete()) {
                enemyBrick->nextLevel();
            }

            return;
        }
    }

    // Check for collision with the bottom border
    if (y() + rect().height() >= scene()->height()) {
        // Decrease health because the ball hit the bottom border
        if (enemyBrick) {
            enemyBrick->decrease();
        }
        // Respawn the ball at the initial position
        setPos(scene()->width() / 2 - rect().width() / 2, scene()->height() / 2 - rect().height() / 2);
    }
}


void Ball::setEnemyBrick(ENEMYBRICK *brick) {
    enemyBrick = brick;

    // Adjust speed based on level
    if (enemyBrick) {
        xVelocity = 5 + enemyBrick->level;
        yVelocity = 5 + enemyBrick->level;
    }
}
