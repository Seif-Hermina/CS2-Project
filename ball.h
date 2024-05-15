#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include "enemybrick.h"


class Ball : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
    Ball(QGraphicsScene *scene, QGraphicsItem *parent = nullptr);
    void move();
    qreal xVelocity;
    qreal yVelocity;
    void setEnemyBrick(ENEMYBRICK *brick);


private:
    void checkCollision();
    ENEMYBRICK *enemyBrick;
};

#endif // BALL_H
