#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QDebug>

#include <iostream>



MainWindow::MainWindow(std::shared_ptr<Game> game, std::shared_ptr<QGraphicsScene> scene, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game_(game),
    scene_(scene)
{
    ui->setupUi(this);


    connect(game_->getRailModel(), &RailLogic::destinationCandidatesChanged, this, &MainWindow::updateNextStations);
    connect(game_->getRailModel(), &RailLogic::backttrackCandidatesChanged, this, &MainWindow::updatePassedStations);

    connect(game_->getPlayerModel(), &PlayerLogic::playerCashChanged, this, &MainWindow::updateMoney);

    connect(ui->gasSlider, &QSlider::valueChanged, this, &MainWindow::changeSpeed);
    connect(ui->directionButton, &QPushButton::clicked, this, &MainWindow::changeDirection);

    connect(ui->nextStationsListWidget, &QListWidget::currentItemChanged, this, &MainWindow::changeNextDestination);
    connect(ui->passedStationsListWidget, &QListWidget::currentItemChanged, this, &MainWindow::changeNextBacktrack);

    connect(game_->getPlayerModel(), &PlayerLogic::availableTrains, this, &MainWindow::updateBuyableTrains);
    connect(game_->getPlayerModel(), &PlayerLogic::ownedTrains, this, &MainWindow::updatePlayerTrains);

    connect(game_->getPlayerModel(), &PlayerLogic::ownedTrainInfo, this, &MainWindow::updateTrainFeatures);
    connect(game_->getPlayerModel(), &PlayerLogic::trainInfo, this, &MainWindow::updateTrainFeatures);

    ui->gameView->setScene(scene_.get());

    scene_->setSceneRect(-250, -240, 508, 475);


    /*ui->buyableTrainsListWidget->addItem(new QListWidgetItem(QString("Pomppuresiina")));
    ui->buyableTrainsListWidget->addItem(new QListWidgetItem(QString("Lättähattujuna")));
    ui->buyableTrainsListWidget->addItem(new QListWidgetItem(QString("Höyryveturi")));
    ui->buyableTrainsListWidget->addItem(new QListWidgetItem(QString("Luotijuna")));*/

    /*ui->ownedTrainsListWidget->addItem(new QListWidgetItem(QString("Pelaajan juna1")));
    ui->ownedTrainsListWidget->addItem(new QListWidgetItem(QString("Pelaajan juna2")));*/

    ui->fixListWidget->addItem(new QListWidgetItem(QString("Pelaajan juna1")));
    ui->fixListWidget->addItem(new QListWidgetItem(QString("Pelaajan juna2")));

    // player's starting cash
    ui->label_4->setNum(game_->getPlayerCash());

    QPen pen(Qt::blue, 1);
    QLineF line(10, 20, 300,300);
    std::shared_ptr<QGraphicsScene> minimapScene = std::make_shared<QGraphicsScene>();
    minimapScene->addLine(line,pen);
    ui->minimapView->setScene(minimapScene.get());
    minimapScene->addLine(line,pen);
    ui->minimapView->show();
    minimapScene->addLine(line,pen);
    ui->minimapView->setScene(minimapScene.get());
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

void MainWindow::on_depotButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_gameButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    game_->gameTabChosen();
}

void MainWindow::on_shopButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    game_->shopTabChosen();
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

void MainWindow::updateNextStations(QList<QString> stations)
{
    ui->nextStationsListWidget->clear();
    for (auto i = stations.begin(); i != stations.end(); ++i){
        ui->nextStationsListWidget->addItem(*i);
    }

}

void MainWindow::updatePassedStations(QList<QString> stations)
{
    ui->passedStationsListWidget->clear();
    for (auto i = stations.begin(); i != stations.end(); ++i){
        ui->passedStationsListWidget->addItem(*i);
    }
}

void MainWindow::changeNextDestination()
{
    if (ui->nextStationsListWidget->currentRow() != -1){
        game_->changeDestination(ui->nextStationsListWidget->currentRow());
    }

}

void MainWindow::changeNextBacktrack()
{
    if (ui->passedStationsListWidget->currentRow() != -1){
        game_->changeBacktrack(ui->passedStationsListWidget->currentRow());
    }
}

void MainWindow::updateTrainFeatures(std::shared_ptr<PlayerTrain> trainInfo)
{


    ui->featuresBLabel->setText("Nopeus: " + QString::number(trainInfo->getSpeed())
                                + ", Kunto: " + QString::number(trainInfo->getShape()));


    ui->costsLabel->setText(QString::number(trainInfo->getPrice()));

}


void MainWindow::updatePlayerTrains(std::vector<std::shared_ptr<PlayerTrain> > ownedTrains)
{
    for (std::shared_ptr<PlayerTrain> owned : ownedTrains) {
        QString name = owned->getName();
        ui->ownedTrainsListWidget->addItem(new QListWidgetItem(name));
    }
}

void MainWindow::updateBuyableTrains(std::vector<std::shared_ptr<PlayerTrain>> trains)
{
    for (std::shared_ptr<PlayerTrain> train : trains) {
        QString trainName = train->getName();
        ui->buyableTrainsListWidget->addItem(new QListWidgetItem(trainName));
    }
}

void MainWindow::updateMoney(int cash)
{
    ui->label_4->setNum(cash);
}

void MainWindow::updateFame()
{

}

void MainWindow::updatePartsToBeRepaired()
{

}


void MainWindow::on_sellButton_clicked()
{
    QString myy = "myy: ";
    if (ui->ownedTrainsListWidget->currentItem() != nullptr){

        qInfo() << myy + ui->ownedTrainsListWidget->currentItem()->text();
    }
}

void MainWindow::on_buyButton_clicked()
{
    QString osta = "osta: ";
    if (ui->buyableTrainsListWidget->currentItem() != nullptr){
        qInfo() << osta + ui->buyableTrainsListWidget->currentItem()->text();
    }
}

void MainWindow::on_fixButton_clicked()
{
    QString korjattava = "korjattu: ";
    if (ui->fixListWidget->currentItem() != nullptr){

        qInfo() << korjattava + ui->fixListWidget->currentItem()->text();
    }
}

void MainWindow::on_confirmButton_clicked()
{
    QString kayta = "käytä: ";

    if (ui->ownedTrainsListWidget->currentItem() != nullptr){
        qInfo() << kayta + ui->ownedTrainsListWidget->currentItem()->text();

    }
}

void MainWindow::on_ownedTrainsListWidget_itemClicked(QListWidgetItem *item)
{
    ui->buyableTrainsListWidget->selectionModel()->clear();
    ui->featuresBLabel->clear();
    game_->wantedOwnedTrainInfo(item->text());

    /*if (item->text() == "Pelaajan juna1") {

        ui->featuresOLabel->setText("Nopeus: 99, kunto 100");
        ui->costsLabel->setText("10");
    }

    else if (item->text() == "Pelaajan juna2") {
        ui->featuresOLabel->setText("Nopeus: 33, kunto 0");
        ui->costsLabel->setText("20");

    }*/
}

void MainWindow::on_buyableTrainsListWidget_itemClicked(QListWidgetItem *item)
{
    ui->ownedTrainsListWidget->selectionModel()->clear();
    ui->featuresOLabel->clear();
    game_->wantedTrainInfo(item->text());

}
