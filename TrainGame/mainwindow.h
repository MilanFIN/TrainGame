#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void vaihda_valikkoon();
    void vaihda_peliin();
    void vaihda_kauppaan();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
