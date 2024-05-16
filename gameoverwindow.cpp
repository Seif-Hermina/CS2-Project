#include "GameOverWindow.h"

GameOverWindow::GameOverWindow(QWidget *parent) : QWidget(parent) {
    // Create the label with the "Game Over" message
    QLabel *label = new QLabel("Game Over", this);

    // Set the font and color of the label
    QFont font("Arial", 24);
    label->setFont(font);
    label->setStyleSheet("QLabel { color : red; }");

    // Center the label in the window
    label->setAlignment(Qt::AlignCenter);

    // Set the layout to center the label
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    setLayout(layout);

    // Resize the window to be large
    resize(400, 300);
}
