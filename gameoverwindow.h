#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class GameOverWindow : public QWidget {
    Q_OBJECT

public:
    explicit GameOverWindow(QWidget *parent = nullptr);
};

#endif // GAMEOVERWINDOW_H
