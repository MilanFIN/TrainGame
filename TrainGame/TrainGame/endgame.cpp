#include "endgame.h"
#include "ui_endgame.h"

endGame::endGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::endGame)
{
    ui->setupUi(this);
    connect(ui->closeButton, &QPushButton::clicked, this, &endGame::close);
}

endGame::~endGame()
{
    delete ui;
}
