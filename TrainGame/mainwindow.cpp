#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(std::shared_ptr<Game> game, std::shared_ptr<QGraphicsScene> scene, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game_(game),
    scene_(scene)
{
    ui->setupUi(this);
    connect(ui->valikkoButton, &QPushButton::clicked, this, &MainWindow::vaihda_valikkoon);
    connect(ui->peliButton, &QPushButton::clicked, this, &MainWindow::vaihda_peliin);
    connect(ui->kauppaButton, &QPushButton::clicked, this, &MainWindow::vaihda_kauppaan);


    ui->peliView->setScene(scene_.get());

    scene_->setSceneRect(-250, -240, 508, 275);
    scene_->setBackgroundBrush(QBrush(QColor(0, 255, 0)));

    auto item_ = new QGraphicsPixmapItem(QPixmap("./img/rail.png"));
    item_->setPos(100,100);
    scene_->addItem(item_);

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


