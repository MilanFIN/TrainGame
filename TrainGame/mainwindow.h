#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "kauppa.h"
#include "valikko.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_valikkoButton_clicked();
    void on_kauppaButton_clicked();

private:
    Ui::MainWindow *ui;
    Kauppa *kauppa;
    Valikko *valikko;
};

#endif // MAINWINDOW_H
