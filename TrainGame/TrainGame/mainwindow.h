#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
#include <QGraphicsScene>
#include <memory>
#include <QGraphicsPixmapItem>
#include <QListWidgetItem>
#include <QList>
#include <QString>
#include <httpengine.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(std::shared_ptr<Game> game, std::shared_ptr<QGraphicsScene> scene,
                        std::shared_ptr<QGraphicsScene> miniMapScene, QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent( QKeyEvent* pEvent );

    //void updateBuyOrSellText(String operation, int count);

public slots:
    void on_shopButton_clicked();
    void on_gameButton_clicked();
    void on_depotButton_clicked();

    //slots for speed slider and direction button
    void changeSpeed();
    void changeDirection();

    void updateActiveTrain(QString trainName);

    void updateMinimap();
    //slot for recieving new possible destination candidates
    void updateNextStations(QList<QString> stations);
    //slot for recieving new possible backtracking candidates
    void updatePassedStations(QList<QString> stations);
    //vastaanottaa seuraavan ja edellisen aseman tiedot
    void updatePreviousAndNext(QString previous, QString next);

    //slot that informs controller that the choise of destination station
    //has changed
    void changeNextDestination();
    void changeNextBacktrack();

    void updateTrainFeatures(std::shared_ptr<PlayerTrain> trainInfo);
    void updateDepotList(std::vector<std::shared_ptr<PlayerTrain>> brTrains);

    void updatePlayerTrains(std::vector<std::shared_ptr<PlayerTrain>> ownedTrains);
    void updateBuyableTrains(std::vector<std::shared_ptr<PlayerTrain> > Trains);
    void updateMoney(int cash);
    void updateFame(int fame);
    void updatePartsToBeRepaired();

    void on_sellButton_clicked();
    void on_buyButton_clicked();
    void on_fixButton_clicked();
    void on_confirmButton_clicked();

    void on_ownedTrainsListWidget_itemClicked(QListWidgetItem *item);
    void on_fixListWidget_itemClicked(QListWidgetItem *item);
    void on_buyableTrainsListWidget_itemClicked(QListWidgetItem *item);

    void trainRepaired();
    void disableGame();

    void updateBrokenTrainInfo(std::shared_ptr<PlayerTrain> brokenTrain);

    void obstacleRemoved(int fameReward, int moneyReward);

    void updateObstacleInfo(QString stations, QString track, QString threatLevel);

    void actionFailed(QString msg);


signals:
private:
    Ui::MainWindow *ui;
    std::shared_ptr<Game> game_;
    std::shared_ptr<QGraphicsScene> scene_;
    std::shared_ptr<QGraphicsScene> miniMapScene_;


};

#endif // MAINWINDOW_H
