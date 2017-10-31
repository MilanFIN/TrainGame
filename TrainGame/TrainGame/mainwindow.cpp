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

    ui->buyableTrainsListWidget->addItem(new QListWidgetItem(QString("Pomppuresiina")));
    ui->buyableTrainsListWidget->addItem(new QListWidgetItem(QString("Lättähattujuna")));
    ui->buyableTrainsListWidget->addItem(new QListWidgetItem(QString("Höyryveturi")));
    ui->buyableTrainsListWidget->addItem(new QListWidgetItem(QString("Luotijuna")));

    ui->ownedListWidget->addItem(new QListWidgetItem(QString("Pelaajan juna1")));
    ui->ownedListWidget->addItem(new QListWidgetItem(QString("Pelaajan juna2")));

    ui->ownedDetailsListWidget->addItem(new QListWidgetItem(QString("Nopeus: 100, kunto: 100 jne")));
    ui->buyableDetailsListWidget->addItem(new QListWidgetItem(QString("Nopeus: 100, kunto: 100 jne")));

    ui->nextStationsListWidget->addItem(new QListWidgetItem(QString("TURKU")));
    ui->nextStationsListWidget->addItem(new QListWidgetItem(QString("JNE")));

    ui->passedStationsListWidget->addItem(new QListWidgetItem(QString("PASILA")));
    ui->passedStationsListWidget->addItem(new QListWidgetItem(QString("JNE")));



    QImage kuva(":/kuvat/rautatiet.png");
    QImage kuvaScaled = kuva.scaled(400,400,Qt::KeepAspectRatio);
    QGraphicsScene* minimapScene = new QGraphicsScene();
    ui->minimapView->setScene(minimapScene);
    QGraphicsPixmapItem* rautatiet = new QGraphicsPixmapItem(QPixmap::fromImage(kuvaScaled));
    minimapScene->addItem(rautatiet);
    ui->minimapView->show();

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


void MainWindow::on_setTrainButton_clicked()
{

}
