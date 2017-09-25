#ifndef VALIKKO_H
#define VALIKKO_H

#include <QDialog>
#include <mainwindow.h>
#include <kauppa.h>


namespace Ui {
class Valikko;
}

class Valikko : public QDialog
{
    Q_OBJECT

public:
    explicit Valikko(QWidget *parent = 0);
    ~Valikko();

private slots:
    void on_peliButton_clicked();
    void on_kauppaButton_clicked();

private:
    Ui::Valikko *ui;
    MainWindow *peli;
    Kauppa *kauppa;

};

#endif // VALIKKO_H
