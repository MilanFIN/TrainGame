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


private slots:
    void vaihda_valikkoon();
    void vaihda_peliin();
    void vaihda_kauppaan();
    void muuta_nopeus();
    void vaihda_suunta();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<Game> game_;
    std::shared_ptr<QGraphicsScene> scene_;
};

#endif // MAINWINDOW_H
