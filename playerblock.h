#ifndef PLAYERBLOCK_H
#define PLAYERBLOCK_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QRectF>

class PlayerBlock : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:

    void keyPressEvent(QKeyEvent * event);
    PlayerBlock(QGraphicsScene *scene, QGraphicsItem *parent = nullptr);


private:
    QRectF rect;
    qreal xVelocity;
    qreal speed;
    qreal width;
    qreal height;


};


#endif // PLAYERBLOCK_H
