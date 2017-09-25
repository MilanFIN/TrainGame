#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_valikkoButton_clicked()
{
    close();
    valikko = new Valikko();
    valikko->show();
}

void MainWindow::on_kauppaButton_clicked()
{
    close();
    kauppa = new Kauppa();
    kauppa->show();
}
