#ifndef GAME_H
#define GAME_H

#include "playerblock.h"
#include "enemybrick.h"
#include "ball.h"

#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>

class game: public QGraphicsView {
public:
    game(QWidget *parent=NULL);

private:
    QGraphicsView *view;
    QGraphicsScene *scene;
};

#endif // GAME_H
