#include "levelpassed.h"

Levelpassed::Levelpassed(QWidget *parent) : QWidget(parent) {
    // Create the label with the "Level Passed!" message
    QLabel *label = new QLabel("Level Passed!", this);

    // Set the font and color of the label
    QFont font("Arial", 24);
    label->setFont(font);
    label->setStyleSheet("QLabel { color : blue; }");

    // Center the label in the window
    label->setAlignment(Qt::AlignCenter);

    // Create a label for the instruction
    QLabel *instructionLabel = new QLabel("Press space to continue to the next level", this);

    // Set the font and color of the instruction label
    QFont instructionFont("Arial", 12);
    instructionLabel->setFont(instructionFont);
    instructionLabel->setStyleSheet("QLabel { color : black; }");

    // Center the instruction label in the window
    instructionLabel->setAlignment(Qt::AlignCenter);

    // Set the layout to center the labels
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(instructionLabel); // Add the instruction label to the layout
    setLayout(layout);

    // Resize the window to be large enough
    resize(400, 300);
}
