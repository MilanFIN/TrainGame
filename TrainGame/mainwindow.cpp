#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>




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
    connect(ui->kaasuSlider, &QSlider::valueChanged, this, &MainWindow::muuta_nopeus);
    connect(ui->suuntaButton, &QPushButton::clicked, this, &MainWindow::vaihda_suunta);

    ui->peliView->setScene(scene_.get());

    scene_->setSceneRect(-250, -240, 508, 475);
    scene_->setBackgroundBrush(QBrush(QColor(0, 255, 0)));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *pEvent)
{
    if (pEvent->key() == Qt::Key_Space){
        game_->removeBlockage();
    }
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

void MainWindow::muuta_nopeus()
{
    game_->setSpeed(ui->kaasuSlider->value()/10);
}

void MainWindow::vaihda_suunta()
{
    game_->changeDirection();
    if (ui->suuntaLabel->text() == "Eteen"){
        ui->suuntaLabel->setText("Taakse");
    }
    else {
        ui->suuntaLabel->setText("Eteen");
    }
}


