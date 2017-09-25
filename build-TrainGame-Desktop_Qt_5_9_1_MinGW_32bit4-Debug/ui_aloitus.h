/********************************************************************************
** Form generated from reading UI file 'aloitus.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALOITUS_H
#define UI_ALOITUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Aloitus
{
public:
    QLabel *TrainGameLabel;
    QLineEdit *userName;
    QPushButton *jatkaButton;
    QPushButton *lopetaButton;

    void setupUi(QDialog *Aloitus)
    {
        if (Aloitus->objectName().isEmpty())
            Aloitus->setObjectName(QStringLiteral("Aloitus"));
        Aloitus->resize(419, 390);
        TrainGameLabel = new QLabel(Aloitus);
        TrainGameLabel->setObjectName(QStringLiteral("TrainGameLabel"));
        TrainGameLabel->setGeometry(QRect(140, 50, 151, 31));
        QFont font;
        font.setPointSize(10);
        TrainGameLabel->setFont(font);
        TrainGameLabel->setAlignment(Qt::AlignCenter);
        userName = new QLineEdit(Aloitus);
        userName->setObjectName(QStringLiteral("userName"));
        userName->setGeometry(QRect(130, 130, 181, 31));
        jatkaButton = new QPushButton(Aloitus);
        jatkaButton->setObjectName(QStringLiteral("jatkaButton"));
        jatkaButton->setGeometry(QRect(170, 220, 93, 28));
        lopetaButton = new QPushButton(Aloitus);
        lopetaButton->setObjectName(QStringLiteral("lopetaButton"));
        lopetaButton->setGeometry(QRect(170, 270, 93, 28));

        retranslateUi(Aloitus);

        QMetaObject::connectSlotsByName(Aloitus);
    } // setupUi

    void retranslateUi(QDialog *Aloitus)
    {
        Aloitus->setWindowTitle(QApplication::translate("Aloitus", "Aloitus", Q_NULLPTR));
        TrainGameLabel->setText(QApplication::translate("Aloitus", "TrainGame", Q_NULLPTR));
        userName->setPlaceholderText(QApplication::translate("Aloitus", "Your name", Q_NULLPTR));
        jatkaButton->setText(QApplication::translate("Aloitus", "Jatka", Q_NULLPTR));
        lopetaButton->setText(QApplication::translate("Aloitus", "Lopeta", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Aloitus: public Ui_Aloitus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALOITUS_H
