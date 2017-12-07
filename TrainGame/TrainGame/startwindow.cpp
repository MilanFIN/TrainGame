#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    connect(ui->start, &QPushButton::clicked, this, &StartWindow::close);
}

StartWindow::~StartWindow()
{
    delete ui;
}
