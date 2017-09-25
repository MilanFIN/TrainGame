#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->valikkoButton, &QPushButton::clicked, this, &MainWindow::vaihda_valikkoon);
    connect(ui->peliButton, &QPushButton::clicked, this, &MainWindow::vaihda_peliin);
    connect(ui->kauppaButton, &QPushButton::clicked, this, &MainWindow::vaihda_kauppaan);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::vaihda_valikkoon() {

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::vaihda_peliin() {

    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::vaihda_kauppaan() {

    ui->stackedWidget->setCurrentIndex(2);
}


