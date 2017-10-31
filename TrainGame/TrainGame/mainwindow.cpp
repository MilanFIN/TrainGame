#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>




MainWindow::MainWindow(std::shared_ptr<Game> game, std::shared_ptr<QGraphicsScene> scene, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game_(game),
    scene_(scene)
{
    ui->setupUi(this);
    connect(ui->depotButton, &QPushButton::clicked, this, &MainWindow::goToDepot);
    connect(ui->gameButton, &QPushButton::clicked, this, &MainWindow::goToGame);
    connect(ui->shopButton, &QPushButton::clicked, this, &MainWindow::goToShop);
    connect(ui->gasSlider, &QSlider::valueChanged, this, &MainWindow::changeSpeed);
    connect(ui->directionButton, &QPushButton::clicked, this, &MainWindow::changeDirection);
    connect(ui->buyButton, &QPushButton::clicked, this, &MainWindow::buyTrain);
    connect(ui->sellButton, &QPushButton::clicked, this, &MainWindow::sellTrain);
    connect(ui->setTrainButton, &QPushButton::clicked, this, &MainWindow::setPlayerTrain);
    connect(ui->fixButton, &QPushButton::clicked, this, &MainWindow::fixTrain);

    ui->gameView->setScene(scene_.get());

    scene_->setSceneRect(-250, -240, 508, 475);
    scene_->setBackgroundBrush(QBrush(QColor(0, 255, 0)));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *pEvent)
{
    if (pEvent->key() == Qt::Key_Space){
        game_->removeBlockage();
    }
}

void MainWindow::goToDepot() {

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::goToGame() {

    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::goToShop() {

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::changeSpeed()
{
    game_->setSpeed(ui->gasSlider->value()/10);
}

void MainWindow::changeDirection()
{
    game_->changeDirection();

    if (ui->directionLabel->text() == "Eteen"){
        ui->directionLabel->setText("Taakse");
    }
    else {
        ui->directionLabel->setText("Eteen");
    }
}

void MainWindow::updateMinimap()
{

}

void MainWindow::updateNextStations()
{

}

void MainWindow::updatePassedStations()
{

}

void MainWindow::updatePlayerTrains()
{

}

void MainWindow::updateBuyableTrains()
{

}

void MainWindow::updateMoney()
{

}

void MainWindow::updateFame()
{

}

void MainWindow::updatePartsToBeRepaired()
{

}

void MainWindow::buyTrain()
{

}

void MainWindow::sellTrain()
{

}

void MainWindow::fixTrain()
{

}

void MainWindow::setPlayerTrain()
{

}

