#include "kauppa.h"
#include "ui_kauppa.h"

Kauppa::Kauppa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kauppa)
{
    ui->setupUi(this);
}

Kauppa::~Kauppa()
{
    delete ui;
}

void Kauppa::on_pelaaButton_clicked()
{
    close();
    peli = new MainWindow();
    peli->show();
}

void Kauppa::on_valikkoButton_clicked()
{
    close();
    valikko = new Valikko();
    valikko->show();
}
