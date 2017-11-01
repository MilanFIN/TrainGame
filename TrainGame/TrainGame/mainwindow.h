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
#include "raillogic.h"


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

public slots:
    void on_shopButton_clicked();
    void on_gameButton_clicked();
    void on_depotButton_clicked();

    void changeSpeed();
    void changeDirection();

    void updateMinimap();
    void updateNextStations(QList<QString> stations);
    void updatePassedStations(QList<QString> stations);
    void updatePlayerTrains();
    void updateBuyableTrains();
    void updateMoney();
    void updateFame();
    void updatePartsToBeRepaired();

    void on_sellButton_clicked();
    void on_buyButton_clicked();
    void on_fixButton_clicked();
    void on_confirmButton_clicked();

    void on_ownedTrainsListWidget_itemClicked(QListWidgetItem *item);

    void on_buyableTrainsListWidget_itemClicked(QListWidgetItem *item);

signals:
private:
    Ui::MainWindow *ui;
    std::shared_ptr<Game> game_;
    std::shared_ptr<QGraphicsScene> scene_;
};

#endif // MAINWINDOW_H
