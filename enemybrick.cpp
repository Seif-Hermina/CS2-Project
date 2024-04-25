#include "enemybrick.h"

#include <QGraphicsRectItem>
#include <QBrush>

ENEMYBRICK::ENEMYBRICK(QGraphicsItem *parent ): QGraphicsRectItem(parent) {
    setRect(0,0,50,20);
    QBrush brush;
    brush.setColor(Qt::red);
    setBrush(brush);
}
