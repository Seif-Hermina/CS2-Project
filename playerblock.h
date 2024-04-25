#ifndef PLAYERBLOCK_H
#define PLAYERBLOCK_H

#include <QObject>
#include <QRectF>

class PlayerBlock : public QObject
{
    Q_OBJECT
public:
    explicit PlayerBlock(QObject *parent = nullptr);
    QRectF getRect() const;
    void setRect(const QRectF &value);
    qreal getXVelocity() const;
    void setXVelocity(const qreal &value);
    void moveLeft();
    void moveRight();

signals:
    void hitWall();

private:
    QRectF rect;
    qreal xVelocity;
    qreal speed;
    qreal width;
    qreal height;
};

#endif // PLAYERBLOCK_H
