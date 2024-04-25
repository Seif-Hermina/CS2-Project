#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include "playerblock.h"

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = nullptr);
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    PlayerBlock *playerBlock;
};

#endif // GAMESCENE_H
