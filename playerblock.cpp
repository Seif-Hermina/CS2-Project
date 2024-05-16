#include "playerblock.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QBrush>

PlayerBlock::PlayerBlock(QGraphicsScene *scene, QGraphicsItem *parent) : QGraphicsRectItem(parent){

    setRect(0, 0, 200, 20);

    setPos(scene->width()/2, scene->height() - 50);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    scene->addItem(this);

}

void PlayerBlock::keyPressEvent(QKeyEvent *event)
{
    // *******  Event Handling for the Player ********
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0) // to prevent the player from getting out of the screen
        {
            setPos(x()-25,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+235<800) // to prevent the player from getting out of the screen
            setPos(x()+25,y());
    }
}

