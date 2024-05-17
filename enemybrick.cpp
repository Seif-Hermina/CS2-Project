#include "enemybrick.h"
#include "GameOverWindow.h"
#include "ball.h"
#include "congratswindow.h"
#include "levelpassed.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QApplication>
#include <QGraphicsView>

ENEMYBRICK::ENEMYBRICK(QGraphicsScene *scene, QGraphicsItem *parent) : QGraphicsRectItem(parent), m_scene(scene) {
    setRect(0, 100, 160, 30);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);

    score = 0;
    health = 3;
    level = 1;

    QFont font;
    font.setPointSize(30);

    QColor color1(Qt::blue);
    scoreMsg = new QGraphicsTextItem;
    scoreMsg->setFont(font);
    scoreMsg->setDefaultTextColor(color1);
    scoreMsg->setPos(650, 10);
    m_scene->addItem(scoreMsg);

    QColor color2(Qt::red);
    healthMsg = new QGraphicsTextItem;
    healthMsg->setFont(font);
    healthMsg->setDefaultTextColor(color2);
    healthMsg->setPos(10, 10);
    font.setPointSize(72);
    m_scene->addItem(healthMsg);
}

void ENEMYBRICK::spawnEnemyBricks(int level) {
    const int rowCount = 1 + level; // Increase the number of rows with each level
    const int colCount = 5; // number of columns
    const int brickWidth = 160;
    const int brickHeight = 30;

    // Spawning rows and columns of bricks
    for (int col = 0; col < colCount; ++col) {
        for (int row = 0; row < rowCount; ++row) {
            ENEMYBRICK* brick = new ENEMYBRICK(m_scene);

            // Calculating position of each brick in the grid
            int x = col * brickWidth;
            int y = row * brickHeight;

            // Setting the position
            brick->setPos(x, y);

            m_scene->addItem(brick);
        }
    }
}

void ENEMYBRICK::increase() {
    // Update the score and the score message
    score++;
    scoreMsg->setPlainText((QString("Score: ") + QString::number(score)));
}

bool ENEMYBRICK::checkLevelComplete() {
    // Check if the score matches the number of bricks for the current level
    int totalBricks = (1 + level) * (5);
    bool levelComplete = score >= totalBricks;
    return levelComplete;
}

void ENEMYBRICK::nextLevel() {
    if (level < 5) { // Check if the level cap is hit or not
        level++;
        score = 0; // Reset score for new level
        scoreMsg->setPlainText(QString("Score: ") + QString::number(score));

        // Remove all existing bricks
        foreach (QGraphicsItem *item, m_scene->items()) {
            if (ENEMYBRICK *brick = dynamic_cast<ENEMYBRICK *>(item)) {
                m_scene->removeItem(brick);
                delete brick;
            }
        }


        // Spawn new set of bricks for the next level
        spawnEnemyBricks(level);

        // Reset ball speed and position
        respawnBall();
        Levelpassed *levelpassed = new Levelpassed();
        levelpassed->show();
    } else {
        //! add here the congrats window with a button to exit. don't forget to remove the debug too.
        Congratswindow *congratswindow = new Congratswindow();
        congratswindow->show();

        // Close the main game window
        QWidget *mainWindow = m_scene->views().at(0)->window();
        mainWindow->close();
       // qDebug() << "Game Over! Reached maximum level.";
    }
}

void ENEMYBRICK::decrease() {
    health--;
    healthMsg->setPlainText(QString("Health: ") + QString::number(health));

    if (health <= 0) {
        GameOverWindow *gameOverWindow = new GameOverWindow();
        gameOverWindow->show();

        // Close the main game window
        QWidget *mainWindow = m_scene->views().at(0)->window();
        mainWindow->close();
    } else {
        respawnBall();
    }
}

void ENEMYBRICK::respawnBall() {
    // Find the existing ball in the scene and delete it
    foreach (QGraphicsItem *item, m_scene->items()) {
        if (Ball *ball = dynamic_cast<Ball *>(item)) {
            m_scene->removeItem(ball);
            delete ball;
            break;
        }
    }

    // Create a new ball and add it to the scene
    Ball *newBall = new Ball(m_scene);
    newBall->setPos(400, 400);
    m_scene->addItem(newBall);
    newBall->setEnemyBrick(this); // Link the new ball to the enemy brick
}
