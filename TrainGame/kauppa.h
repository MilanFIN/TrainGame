#ifndef KAUPPA_H
#define KAUPPA_H

#include <QDialog>
#include <mainwindow.h>
#include <valikko.h>

namespace Ui {
class Kauppa;
}

class Kauppa : public QDialog
{
    Q_OBJECT

public:
    explicit Kauppa(QWidget *parent = 0);
    ~Kauppa();

private slots:
    void on_pelaaButton_clicked();
    void on_valikkoButton_clicked();

private:
    Ui::Kauppa *ui;
    MainWindow *peli;
    Valikko *valikko;

};

#endif // KAUPPA_H
