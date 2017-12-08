#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "datareader.h"
#include "endgame.h"
#include <QKeyEvent>
#include <QMessageBox>
#include <QDebug>
#include <iostream>



MainWindow::MainWindow(std::shared_ptr<Game> game, std::shared_ptr<QGraphicsScene> scene,
                       std::shared_ptr<QGraphicsScene> miniMapScene, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game_(game),
    scene_(scene),
    miniMapScene_(miniMapScene)
{
    ui->setupUi(this);


    connect(game_->getRailModel(), &RailLogic::destinationCandidatesChanged, this, &MainWindow::updateNextStations);
    connect(game_->getRailModel(), &RailLogic::backttrackCandidatesChanged, this, &MainWindow::updatePassedStations);

    connect(game_->getRailModel(), &RailLogic::signalDestAndPrevious, this, &MainWindow::updatePreviousAndNext);


    connect(game_->getRailModel(), &RailLogic::naviInfoUpdate, this, &MainWindow::updateNaviToUi);

    connect(game_->getPlayerModel(), &PlayerLogic::playerCashChanged, this, &MainWindow::updateMoney);
    connect(game_->getPlayerModel(), &PlayerLogic::playerFameChanged, this, &MainWindow::updateFame);

    connect(ui->gasSlider, &QSlider::valueChanged, this, &MainWindow::changeSpeed);
    connect(ui->directionButton, &QPushButton::clicked, this, &MainWindow::changeDirection);

    connect(ui->nextStationsListWidget, &QListWidget::currentItemChanged, this, &MainWindow::changeNextDestination);
    connect(ui->passedStationsListWidget, &QListWidget::currentItemChanged, this, &MainWindow::changeNextBacktrack);

    connect(game_->getPlayerModel(), &PlayerLogic::availableTrains, this, &MainWindow::updateBuyableTrains);
    connect(game_->getPlayerModel(), &PlayerLogic::ownedTrains, this, &MainWindow::updatePlayerTrains);
    connect(game_->getPlayerModel(), &PlayerLogic::activeTrainChanged, this, &MainWindow::updateActiveTrain);

    connect(game_->getPlayerModel(), &PlayerLogic::ownedTrainInfo, this, &MainWindow::updateTrainFeatures);
    connect(game_->getPlayerModel(), &PlayerLogic::trainInfo, this, &MainWindow::updateTrainFeatures);

    connect(game_->getPlayerModel(), &PlayerLogic::showBrokenTrains, this, &MainWindow::updateDepotList);
    connect(game_->getPlayerModel(), &PlayerLogic::brokenTrain, this, &MainWindow::updateBrokenTrainInfo);

    connect(game_->getPlayerModel(), &PlayerLogic::trainRepaired, this, &MainWindow::trainRepaired);
    connect(game_->getPlayerModel(), &PlayerLogic::notEnoughMoney, this, &MainWindow::actionFailed);


    connect(game_->getObstacleModel(), &ObstacleLogic::obstacleRemoved, this, &MainWindow::obstacleRemoved);
    connect(game_->getObstacleModel(), &ObstacleLogic::obstacleCreated, this, &MainWindow::updateObstacleInfo);

    connect(game_->getPlayerModel(), &PlayerLogic::notAbleToPlay, this, &MainWindow::disableGame);
    connect(game_->getPlayerModel(), &PlayerLogic::shopActionFailed, this, &MainWindow::actionFailed);

    connect(game_->getAiTrainModel(), &VrTrainManager::message, this, &MainWindow::updateMessageLabel);
    connect(game_->getPlayerModel()->activeTrain().get(), &PlayerTrain::message, this, &MainWindow::updateMessageLabel);

    connect(game_.get(), &Game::endGameSignal, this, &MainWindow::endGameWindow);

    connect(clearTimer_, SIGNAL(timeout()), this, SLOT(clearMessage()));

    connect(game_.get(), &Game::decreaseFame, this, &MainWindow::updateFame);

    ui->gameView->setScene(scene_.get());

    scene_->setSceneRect(-250, -240, 508, 475);

    ui->minimapView->setScene(miniMapScene_.get());
    miniMapScene_->setSceneRect(-140, -210, 275, 415);


    // player's starting cash
    ui->moneyLabel->setNum(game_->getPlayerMoney());
    ui->featuresTextOLabel->setText(QString("Aktiivinen Juna: "));
    ui->featuresOLabel->setText(game_->getPlayerModel()->activeTrain()->getName());

    game_->getPlayerModel()->getOwnedTrains();
    game_->getPlayerModel()->getAvailableTrainsFromShop();
    ui->stackedWidget->setCurrentIndex(0);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::mousePressEvent(QMouseEvent *Mevent)
{
    //figure out if we clicked the gameview graphcics view are
    QPoint clickLocation = ui->gameView->mapFromParent(Mevent->pos());
    if (ui->gameView->rect().contains(clickLocation)){
        //try to remove an obstacle
        game_->removeBlockage();
    }
}

void MainWindow::on_depotButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    game_->depotTabChosen();
    ui->gasSlider->setValue(0);
}

void MainWindow::on_gameButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    game_->gameTabChosen();
    ui->gasSlider->setValue(0);
}

void MainWindow::on_shopButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    game_->shopTabChosen();
    ui->gasSlider->setValue(0);
}

void MainWindow::changeSpeed()
{
    game_->setSpeed(ui->gasSlider->value());

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

void MainWindow::updateActiveTrain(QString trainName)
{
    ui->featuresOLabel->setText(trainName);
}

void MainWindow::updateNextStations(QList<QString> stations)
{
    ui->nextStationsListWidget->clear();
    for (auto i = stations.begin(); i != stations.end(); ++i){
        ui->nextStationsListWidget->addItem(*i);
    }
    game_->updateNavi();

}

void MainWindow::updatePassedStations(QList<QString> stations)
{
    ui->passedStationsListWidget->clear();
    for (auto i = stations.begin(); i != stations.end(); ++i){
        ui->passedStationsListWidget->addItem(*i);
    }
}

void MainWindow::updatePreviousAndNext(QString previous, QString next)
{
    ui->nextStation->setText(next);
    ui->previousStation->setText(previous);

    //tell game to do stuff if necessary
    game_.get()->railChanged();
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

void MainWindow::updateDepotList(std::vector<std::shared_ptr<PlayerTrain>> brTrains)
{
    ui->fixListWidget->clear();
    if (brTrains.size() != 0) {

        for (std::shared_ptr<PlayerTrain> brokenTrain : brTrains) {
            ui->fixListWidget->addItem(new QListWidgetItem(brokenTrain->getName()));
        }
    }

}


void MainWindow::updatePlayerTrains(std::vector<std::shared_ptr<PlayerTrain> > ownedTrains)
{
    ui->ownedTrainsListWidget->clear();
    for (std::shared_ptr<PlayerTrain> owned : ownedTrains) {
        QString name = owned->getName();
        ui->ownedTrainsListWidget->addItem(new QListWidgetItem(name));
    }
}

void MainWindow::updateBuyableTrains(std::vector<std::shared_ptr<PlayerTrain>> trains)
{
    ui->buyableTrainsListWidget->clear();
    for (std::shared_ptr<PlayerTrain> train : trains) {
        QString trainName = train->getName();
        ui->buyableTrainsListWidget->addItem(new QListWidgetItem(trainName));
    }
}

void MainWindow::updateMoney(int cash)
{
    ui->moneyLabel->setNum(cash);
}

void MainWindow::updateFame(int fame)
{
    ui->fameLabel->setNum(fame);
}



void MainWindow::on_sellButton_clicked()
{

    if (ui->ownedTrainsListWidget->currentItem() != nullptr){


        int index = ui->ownedTrainsListWidget->currentRow();

        game_->sellTrain(index);

        ui->featuresBLabel->clear();
        ui->costsLabel->clear();


    }
}

void MainWindow::on_buyButton_clicked()
{

    if (ui->buyableTrainsListWidget->currentItem() != nullptr){
        QString TrainName = ui->buyableTrainsListWidget->currentItem()->text();
        int index = ui->buyableTrainsListWidget->currentRow();

        game_->buyNewTrain(TrainName, index);

        ui->featuresBLabel->clear();
        ui->costsLabel->clear();

    }
}

void MainWindow::on_fixButton_clicked()
{
    if (ui->fixListWidget->currentItem() != nullptr)
    {
        int rowIndex = ui->fixListWidget->currentRow();
        game_->repairPlayerTrain(rowIndex);
    }
}

void MainWindow::on_confirmButton_clicked()
{
    // if empty do nothing
    if (ui->ownedTrainsListWidget->currentItem() != nullptr)
    {
        int rowIndex = ui->ownedTrainsListWidget->currentRow();
        game_->setActiveTrain(rowIndex);
        ui->gameButton->setDisabled(false);
    }
}

void MainWindow::on_ownedTrainsListWidget_itemClicked(QListWidgetItem *item)
{
    ui->buyableTrainsListWidget->selectionModel()->clear();
    ui->featuresBLabel->clear();
    game_->wantedOwnedTrainInfo(item->text());
}

void MainWindow::on_fixListWidget_itemClicked(QListWidgetItem *item)
{   
    ui->currShape->clear();
    ui->optimalShape->clear();
    ui->repairCostLabel->clear();
    game_->fixlistTrainInfo(item->text());
}

void MainWindow::on_buyableTrainsListWidget_itemClicked(QListWidgetItem *item)
{   
    ui->ownedTrainsListWidget->selectionModel()->clear();
    ui->featuresBLabel->clear();
    game_->wantedTrainInfo(item->text());

}

void MainWindow::trainRepaired()
{
    game_->depotTabChosen();
    ui->currShape->clear();
    ui->optimalShape->clear();
    ui->repairCostLabel->clear();
}

void MainWindow::disableGame()
{
    QMessageBox::warning(this, "Ei junaa", "Aktiivista junaa ei ole asetettu, et voi pelata");
    ui->gameButton->setDisabled(true);
}


void MainWindow::updateBrokenTrainInfo(std::shared_ptr<PlayerTrain> brokenTrain)
{
    short absShape = brokenTrain->getAbsoluteShape();
    short currShape = brokenTrain->getShape();
    unsigned short cost = brokenTrain->getRepairCost();


    ui->currShape->setText(QString::number(currShape));
    ui->optimalShape->setText(QString::number(absShape));
    ui->repairCostLabel->setText(QString::number(cost));
}

void MainWindow::obstacleRemoved(int fameReward, int moneyReward)
{
    int currentMoney = game_->getPlayerMoney();
    int currentFame = ui->fameTextLabel->text().toInt();


    int newMoney = currentMoney + moneyReward;
    if (newMoney < 0){
        moneyReward = 0 - currentMoney;
    }
    int newFame = currentFame + fameReward;

    game_->addMoney(moneyReward);
    game_->addFame(fameReward);
    //spawn next obstacle
    game_->spawn();

}

void MainWindow::updateObstacleInfo(QString stations, QString track, QString threatLevel)
{
    ui->blockLocation->setText(stations);
    ui->blockTrack->setText(track);
    ui->blockThreat->setText(threatLevel);

}

void MainWindow::actionFailed(QString msg)
{
    QMessageBox::critical(this, "Virhe", msg);
}

void MainWindow::updateMessageLabel(QString msg)
{
    ui->notificationLabel->setText(msg);
    clearTimer_->start(5000);
}

void MainWindow::clearMessage()
{
    clearTimer_->stop();
    ui->notificationLabel->setText("");
}

void MainWindow::updateNaviToUi(QString info)
{
    ui->naviLabel->setText(info);
}

void MainWindow::endGameWindow()
{
    endGame w;

    w.exec();
    this->close();
}

