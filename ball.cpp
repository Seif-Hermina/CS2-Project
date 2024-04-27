#include "ball.h"
#include <QGraphicsScene>
#include "playerblock.h"
#include "enemybrick.h"
#include <QTimer>
#include <QBrush>
#include <QObject>

Ball::Ball(QGraphicsItem* parent) : QGraphicsEllipseItem(parent), dx(2), dy(-2) {
    setRect(0, 0, 10, 10); // size of the ball
    QBrush bbrush;
    bbrush.setStyle(Qt::SolidPattern);
    bbrush.setColor(Qt::red);
    setBrush(bbrush);
}

void Ball::advance(int phase) {
    if (!phase) return;
    moveBy(dx, dy);
    checkCollision();
}

void Ball::checkCollision() {
    QList<QGraphicsItem*> collisions = scene()->collidingItems(this);
    foreach (QGraphicsItem* item, collisions) {
        if (typeid(*item) == typeid(PlayerBlock)) {
            dy = -dy; // Invert the y-direction
        }
        else if (typeid(*item) == typeid(ENEMYBRICK)) {
            scene()->removeItem(item);
            delete item;
            dy = -dy; // Invert the y-direction
            // Increase score here
        }
        // Add boundaries' collision handling here
    }
}
