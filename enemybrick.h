#ifndef ENEMYBRICK_H
#define ENEMYBRICK_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QBrush>
#include <QObject>

class ENEMYBRICK: public QGraphicsRectItem
{
public:
    explicit ENEMYBRICK(QGraphicsScene *scene, QGraphicsItem *parent = nullptr);
    void spawnEnemyBricks(int level);
    QGraphicsTextItem* scoreMsg;
    QGraphicsTextItem* healthMsg;
    QGraphicsTextItem* endMsg;
    int score = 0;
    int health = 3;
    void increase();
    void decrease();
    void respawnBall();
    int level = 1;
    bool checkLevelComplete();
    void nextLevel();

private:
    QGraphicsScene *m_scene;

};

#endif // ENEMYBRICK_H
