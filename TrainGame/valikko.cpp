#include "valikko.h"
#include "ui_valikko.h"

Valikko::Valikko(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Valikko)
{
    ui->setupUi(this);
}

Valikko::~Valikko()
{
    delete ui;
}

void Valikko::on_peliButton_clicked()
{
    close();
    peli = new MainWindow();
    peli->show();
}

void Valikko::on_kauppaButton_clicked()
{
    close();
    kauppa = new Kauppa();
    kauppa->show();
}
