/*#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "playerblock.h"

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = nullptr);
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void spawnEnemyBricks(); //spawning bricks
    QGraphicsTextItem* scoreMsg;
    QGraphicsTextItem* healthMsg;
    QGraphicsTextItem* endMsg;
    int score = 0;
    int health = 3;

private:
    PlayerBlock *playerBlock;

};

#endif // GAMESCENE_H
*/
