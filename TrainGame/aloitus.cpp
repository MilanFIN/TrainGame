#include "aloitus.h"
#include "ui_aloitus.h"

Aloitus::Aloitus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aloitus)
{
    ui->setupUi(this);
}

Aloitus::~Aloitus()
{
    delete ui;
}

void Aloitus::on_jatkaButton_clicked()
{
    close();
    //peli = new MainWindow();
    //peli->show();
}

void Aloitus::on_lopetaButton_clicked()
{
    close();
}
