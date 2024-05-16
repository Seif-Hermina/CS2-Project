#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
#include <QGraphicsScene>

class Score: public QGraphicsTextItem
{
public:
    Score(QGraphicsScene *scene, QGraphicsItem *parent = nullptr);
    QGraphicsTextItem* scoreMsg;
};

#endif // SCORE_H
