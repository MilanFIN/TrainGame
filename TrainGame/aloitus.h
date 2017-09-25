#ifndef ALOITUS_H
#define ALOITUS_H

#include <QDialog>
#include "kauppa.h"

namespace Ui {
class Aloitus;
}

class Aloitus : public QDialog
{
    Q_OBJECT

public:
    explicit Aloitus(QWidget *parent = 0);
    ~Aloitus();

private slots:
    void on_jatkaButton_clicked();
    void on_lopetaButton_clicked();

private:
    Ui::Aloitus *ui;
    Kauppa *kauppa;

};

#endif // ALOITUS_H
