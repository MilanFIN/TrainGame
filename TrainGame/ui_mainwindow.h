/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *valikkoPage;
    QListView *listView_3;
    QTextEdit *textEdit;
    QWidget *pelaaPage;
    QGraphicsView *peliView;
    QGraphicsView *rautaTieKarttaView;
    QTextEdit *esteTextEdit;
    QTextEdit *infoTextEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSlider *kaasuSlider;
    QWidget *kauppaPage;
    QPushButton *ostaButton;
    QPushButton *myyButton;
    QLabel *label_4;
    QLabel *label_5;
    QListView *listView;
    QListView *listView_2;
    QPushButton *peliButton;
    QPushButton *valikkoButton;
    QPushButton *kauppaButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1154, 642);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(11, 55, 1131, 511));
        valikkoPage = new QWidget();
        valikkoPage->setObjectName(QStringLiteral("valikkoPage"));
        listView_3 = new QListView(valikkoPage);
        listView_3->setObjectName(QStringLiteral("listView_3"));
        listView_3->setGeometry(QRect(20, 20, 331, 481));
        textEdit = new QTextEdit(valikkoPage);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(803, 30, 291, 461));
        stackedWidget->addWidget(valikkoPage);
        pelaaPage = new QWidget();
        pelaaPage->setObjectName(QStringLiteral("pelaaPage"));
        peliView = new QGraphicsView(pelaaPage);
        peliView->setObjectName(QStringLiteral("peliView"));
        peliView->setGeometry(QRect(315, 20, 511, 481));
        rautaTieKarttaView = new QGraphicsView(pelaaPage);
        rautaTieKarttaView->setObjectName(QStringLiteral("rautaTieKarttaView"));
        rautaTieKarttaView->setGeometry(QRect(850, 20, 256, 261));
        esteTextEdit = new QTextEdit(pelaaPage);
        esteTextEdit->setObjectName(QStringLiteral("esteTextEdit"));
        esteTextEdit->setGeometry(QRect(30, 50, 221, 191));
        infoTextEdit = new QTextEdit(pelaaPage);
        infoTextEdit->setObjectName(QStringLiteral("infoTextEdit"));
        infoTextEdit->setGeometry(QRect(30, 260, 221, 211));
        pushButton = new QPushButton(pelaaPage);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(890, 330, 93, 28));
        pushButton_2 = new QPushButton(pelaaPage);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(1000, 330, 93, 28));
        kaasuSlider = new QSlider(pelaaPage);
        kaasuSlider->setObjectName(QStringLiteral("kaasuSlider"));
        kaasuSlider->setGeometry(QRect(1050, 390, 22, 101));
        kaasuSlider->setOrientation(Qt::Vertical);
        stackedWidget->addWidget(pelaaPage);
        kauppaPage = new QWidget();
        kauppaPage->setObjectName(QStringLiteral("kauppaPage"));
        ostaButton = new QPushButton(kauppaPage);
        ostaButton->setObjectName(QStringLiteral("ostaButton"));
        ostaButton->setGeometry(QRect(500, 120, 141, 51));
        myyButton = new QPushButton(kauppaPage);
        myyButton->setObjectName(QStringLiteral("myyButton"));
        myyButton->setGeometry(QRect(500, 220, 141, 51));
        label_4 = new QLabel(kauppaPage);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(140, 0, 55, 16));
        label_5 = new QLabel(kauppaPage);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(950, 0, 55, 16));
        listView = new QListView(kauppaPage);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(20, 40, 301, 441));
        listView_2 = new QListView(kauppaPage);
        listView_2->setObjectName(QStringLiteral("listView_2"));
        listView_2->setGeometry(QRect(795, 40, 321, 451));
        stackedWidget->addWidget(kauppaPage);
        peliButton = new QPushButton(centralWidget);
        peliButton->setObjectName(QStringLiteral("peliButton"));
        peliButton->setGeometry(QRect(530, 10, 93, 28));
        valikkoButton = new QPushButton(centralWidget);
        valikkoButton->setObjectName(QStringLiteral("valikkoButton"));
        valikkoButton->setGeometry(QRect(370, 10, 93, 28));
        kauppaButton = new QPushButton(centralWidget);
        kauppaButton->setObjectName(QStringLiteral("kauppaButton"));
        kauppaButton->setGeometry(QRect(690, 10, 93, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1154, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "TrainGame", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        ostaButton->setText(QApplication::translate("MainWindow", "Osta", Q_NULLPTR));
        myyButton->setText(QApplication::translate("MainWindow", "Myy", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        peliButton->setText(QApplication::translate("MainWindow", "Pelaa", Q_NULLPTR));
        valikkoButton->setText(QApplication::translate("MainWindow", "Valikko", Q_NULLPTR));
        kauppaButton->setText(QApplication::translate("MainWindow", "Kauppa", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
