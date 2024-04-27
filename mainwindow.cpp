/*#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamescene.h"
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(800, 800);


    view = new QGraphicsView(this);
    view->setFixedSize(800, 800);

    gameScene = new GameScene(this);

    view->setScene(gameScene);

    setCentralWidget(view);

    //gameScene->spawnEnemyBricks();


}

MainWindow::~MainWindow()
{
    delete ui;
}
*/
