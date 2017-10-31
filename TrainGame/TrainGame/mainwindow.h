#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
#include <QGraphicsScene>
#include <memory>
#include <QGraphicsPixmapItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(std::shared_ptr<Game> game, std::shared_ptr<QGraphicsScene> scene, QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent( QKeyEvent* pEvent );

    //void updateBuyOrSellText(String operation, int count);

private slots:
    void goToDepot();
    void goToGame();
    void goToShop();

    void changeSpeed();
    void changeDirection();

    void updateMinimap();
    void updateNextStations();
    void updatePassedStations();
    void updatePlayerTrains();
    void updateBuyableTrains();
    void updateMoney();
    void updateFame();
    void updatePartsToBeRepaired();

    void buyTrain();
    void sellTrain();
    void fixTrain();
    void setPlayerTrain();

    void on_setTrainButton_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<Game> game_;
    std::shared_ptr<QGraphicsScene> scene_;
};

#endif // MAINWINDOW_H
