#ifndef LEVELPASSED_H
#define LEVELPASSED_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class Levelpassed : public QWidget {
    Q_OBJECT

public:
    explicit Levelpassed(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent * event);

};

#endif // LEVELPASSED_H
