#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>

class Ball : public QGraphicsEllipseItem {
public:
    Ball(QGraphicsItem* parent = nullptr);
    void advance(int phase);
    void checkCollision();

private:
    qreal dx; // horizontal velocity
    qreal dy; // vertical velocity
};

#endif // BALL_H
