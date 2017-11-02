#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QDebug>



MainWindow::MainWindow(std::shared_ptr<Game> game, std::shared_ptr<QGraphicsScene> scene, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game_(game),
    scene_(scene)
{
    ui->setupUi(this);


    connect(game_->getRailModel(), &RailLogic::destinationCandidatesChanged, this, &MainWindow::updateNextStations);
    connect(game_->getRailModel(), &RailLogic::backttrackCandidatesChanged, this, &MainWindow::updatePassedStations);



    connect(ui->gasSlider, &QSlider::valueChanged, this, &MainWindow::changeSpeed);
    connect(ui->directionButton, &QPushButton::clicked, this, &MainWindow::changeDirection);

    ui->gameView->setScene(scene_.get());

    scene_->setSceneRect(-250, -240, 508, 475);


    ui->buyableTrainsListWidget->addItem(new QListWidgetItem(QString("Pomppuresiina")));
    ui->buyableTrainsListWidget->addItem(new QListWidgetItem(QString("Lättähattujuna")));
    ui->buyableTrainsListWidget->addItem(new QListWidgetItem(QString("Höyryveturi")));
    ui->buyableTrainsListWidget->addItem(new QListWidgetItem(QString("Luotijuna")));

    ui->ownedTrainsListWidget->addItem(new QListWidgetItem(QString("Pelaajan juna1")));
    ui->ownedTrainsListWidget->addItem(new QListWidgetItem(QString("Pelaajan juna2")));

    ui->fixListWidget->addItem(new QListWidgetItem(QString("Pelaajan juna1")));
    ui->fixListWidget->addItem(new QListWidgetItem(QString("Pelaajan juna2")));



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
}

void MainWindow::on_shopButton_clicked()
{
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

    if (item->text() == "Pelaajan juna1") {

        ui->featuresOLabel->setText("Nopeus: 99, kunto 100");
        ui->costsLabel->setText("10");
    }

    else if (item->text() == "Pelaajan juna2") {
        ui->featuresOLabel->setText("Nopeus: 33, kunto 0");
        ui->costsLabel->setText("20");

    }
}

void MainWindow::on_buyableTrainsListWidget_itemClicked(QListWidgetItem *item)
{
    ui->ownedTrainsListWidget->selectionModel()->clear();
    ui->featuresOLabel->clear();

    if (item->text() == "Lättähattujuna") {

        ui->featuresBLabel->setText("Nopeus: 99, kunto 100");
        ui->costsLabel->setText("30");

    }

    else if (item->text() == "Pomppuresiina") {

        ui->featuresBLabel->setText("Nopeus: 66, kunto 100");
        ui->costsLabel->setText("40");

    }

    else if (item->text() == "Höyryveturi") {

        ui->featuresBLabel->setText("Nopeus: 33, kunto 100");
        ui->costsLabel->setText("50");

    }

    else if (item->text() == "Luotijuna") {

        ui->featuresBLabel->setText("Nopeus: 1, kunto 100");
        ui->costsLabel->setText("60");

    }
}
