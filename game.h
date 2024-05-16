#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

class game: public QGraphicsView {
public:
    game();

private:
    QGraphicsView *view;
    QGraphicsScene *scene;
};

#endif // GAME_H
