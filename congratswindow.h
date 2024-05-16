#ifndef CONGRATSWINDOW_H
#define CONGRATSWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class Congratswindow : public QWidget {
    Q_OBJECT

public:
    explicit Congratswindow(QWidget *parent = nullptr);
};

#endif // CONGRATSWINDOW_H
