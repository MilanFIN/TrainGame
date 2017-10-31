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
    QWidget *depotPage;
    QTextEdit *textEdit;
    QPushButton *fixButton;
    QWidget *gamePage;
    QGraphicsView *gameView;
    QGraphicsView *minimapView;
    QSlider *gasSlider;
    QPushButton *directionButton;
    QLabel *directionLabel;
    QListView *nextStations;
    QListView *passedStations;
    QLabel *comingLabel;
    QLabel *passedLabel;
    QWidget *shopPage;
    QPushButton *buyButton;
    QPushButton *sellButton;
    QLabel *playerTrainsLabel;
    QLabel *buyableTrainsLabel;
    QListView *listView;
    QListView *listView_2;
    QPushButton *setTrainButton;
    QPushButton *gameButton;
    QPushButton *depotButton;
    QPushButton *shopButton;
    QLabel *label;
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
        stackedWidget->setGeometry(QRect(20, 60, 1131, 511));
        depotPage = new QWidget();
        depotPage->setObjectName(QStringLiteral("depotPage"));
        textEdit = new QTextEdit(depotPage);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(510, 40, 321, 461));
        fixButton = new QPushButton(depotPage);
        fixButton->setObjectName(QStringLiteral("fixButton"));
        fixButton->setGeometry(QRect(350, 230, 111, 28));
        fixButton->setStyleSheet(QLatin1String("QPushButton:pressed {\n"
"	background-color: #222222;\n"
"	border: 1px solid #333333;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #66db57;\n"
"}\n"
"QPushButton {\n"
"font: 75 12pt \"Caladea\";\n"
"border: 1px solid #199909;\n"
"border-radius: 6px;\n"
"background-color: #116a06;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #22c70d, stop: 1 #116a06);\n"
"}"));
        stackedWidget->addWidget(depotPage);
        gamePage = new QWidget();
        gamePage->setObjectName(QStringLiteral("gamePage"));
        gameView = new QGraphicsView(gamePage);
        gameView->setObjectName(QStringLiteral("gameView"));
        gameView->setGeometry(QRect(310, 10, 511, 481));
        minimapView = new QGraphicsView(gamePage);
        minimapView->setObjectName(QStringLiteral("minimapView"));
        minimapView->setGeometry(QRect(10, 40, 281, 421));
        gasSlider = new QSlider(gamePage);
        gasSlider->setObjectName(QStringLiteral("gasSlider"));
        gasSlider->setGeometry(QRect(1047, 300, 41, 191));
        gasSlider->setStyleSheet(QLatin1String("QSlider  \n"
"{  \n"
"    background-color: #ddd;   \n"
"    border-style: outset;   \n"
"    border-radius: 10px;   \n"
"}\n"
"QSlider::groove:horizontal  \n"
"{  \n"
"    height: 12px;  \n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);  \n"
"    margin: 2px 0  \n"
"}  \n"
"QSlider::handle:horizontal   \n"
"{  \n"
"    background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 white, stop:1 green);  \n"
"    width: 16px;  \n"
"    height: 16px;  \n"
"    margin: -5px 6px -5px 6px;  \n"
"    border-radius:11px;   \n"
"    border: 3px solid #ffffff;  \n"
"}  \n"
""));
        gasSlider->setMinimum(0);
        gasSlider->setMaximum(99);
        gasSlider->setSliderPosition(0);
        gasSlider->setOrientation(Qt::Vertical);
        directionButton = new QPushButton(gamePage);
        directionButton->setObjectName(QStringLiteral("directionButton"));
        directionButton->setGeometry(QRect(1032, 220, 81, 31));
        directionButton->setStyleSheet(QLatin1String("QPushButton:pressed {\n"
"	background-color: #222222;\n"
"	border: 1px solid #333333;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #ccc5c7;\n"
"}\n"
"QPushButton {\n"
"font: 75 12pt \"Caladea\";\n"
"border: 1px solid #72595e;\n"
"border-radius: 6px;\n"
"background-color: #605053;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #bdbabb, stop: 1 #605053);\n"
"}"));
        directionLabel = new QLabel(gamePage);
        directionLabel->setObjectName(QStringLiteral("directionLabel"));
        directionLabel->setGeometry(QRect(1020, 260, 101, 31));
        directionLabel->setAlignment(Qt::AlignCenter);
        nextStations = new QListView(gamePage);
        nextStations->setObjectName(QStringLiteral("nextStations"));
        nextStations->setGeometry(QRect(850, 120, 61, 371));
        passedStations = new QListView(gamePage);
        passedStations->setObjectName(QStringLiteral("passedStations"));
        passedStations->setGeometry(QRect(930, 120, 61, 371));
        comingLabel = new QLabel(gamePage);
        comingLabel->setObjectName(QStringLiteral("comingLabel"));
        comingLabel->setGeometry(QRect(850, 80, 55, 16));
        passedLabel = new QLabel(gamePage);
        passedLabel->setObjectName(QStringLiteral("passedLabel"));
        passedLabel->setGeometry(QRect(930, 80, 55, 16));
        stackedWidget->addWidget(gamePage);
        shopPage = new QWidget();
        shopPage->setObjectName(QStringLiteral("shopPage"));
        buyButton = new QPushButton(shopPage);
        buyButton->setObjectName(QStringLiteral("buyButton"));
        buyButton->setGeometry(QRect(500, 120, 141, 51));
        buyButton->setStyleSheet(QLatin1String("QPushButton:pressed {\n"
"	background-color: #222222;\n"
"	border: 1px solid #333333;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #66db57;\n"
"}\n"
"QPushButton {\n"
"font: 75 15pt \"Caladea\";\n"
"border: 1px solid #199909;\n"
"border-radius: 6px;\n"
"background-color: #116a06;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #22c70d, stop: 1 #116a06);\n"
"}"));
        sellButton = new QPushButton(shopPage);
        sellButton->setObjectName(QStringLiteral("sellButton"));
        sellButton->setGeometry(QRect(500, 220, 141, 51));
        sellButton->setStyleSheet(QLatin1String("QPushButton:pressed {\n"
"	background-color: #222222;\n"
"	border: 1px solid #333333;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #f04d6e;\n"
"}\n"
"QPushButton {\n"
"font: 75 15pt \"Caladea\";\n"
"border: 1px solid #b20024;\n"
"border-radius: 6px;\n"
"background-color: #ea0533;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #fb2953, stop: 1 #c90029);\n"
"}"));
        playerTrainsLabel = new QLabel(shopPage);
        playerTrainsLabel->setObjectName(QStringLiteral("playerTrainsLabel"));
        playerTrainsLabel->setGeometry(QRect(24, 0, 301, 20));
        playerTrainsLabel->setStyleSheet(QStringLiteral("font: 75 14pt \"Caladea\";"));
        playerTrainsLabel->setAlignment(Qt::AlignCenter);
        buyableTrainsLabel = new QLabel(shopPage);
        buyableTrainsLabel->setObjectName(QStringLiteral("buyableTrainsLabel"));
        buyableTrainsLabel->setGeometry(QRect(794, 0, 321, 20));
        buyableTrainsLabel->setStyleSheet(QStringLiteral("font: 75 14pt \"Caladea\";"));
        buyableTrainsLabel->setAlignment(Qt::AlignCenter);
        listView = new QListView(shopPage);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(20, 40, 301, 261));
        listView_2 = new QListView(shopPage);
        listView_2->setObjectName(QStringLiteral("listView_2"));
        listView_2->setGeometry(QRect(795, 40, 321, 261));
        setTrainButton = new QPushButton(shopPage);
        setTrainButton->setObjectName(QStringLiteral("setTrainButton"));
        setTrainButton->setGeometry(QRect(512, 380, 131, 61));
        stackedWidget->addWidget(shopPage);
        gameButton = new QPushButton(centralWidget);
        gameButton->setObjectName(QStringLiteral("gameButton"));
        gameButton->setGeometry(QRect(530, 10, 93, 28));
        gameButton->setMouseTracking(false);
        gameButton->setStyleSheet(QLatin1String("QPushButton:pressed {\n"
"	background-color: #222222;\n"
"	border: 1px solid #333333;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #66db57;\n"
"}\n"
"QPushButton {\n"
"font: 75 12pt \"Caladea\";\n"
"border: 1px solid #199909;\n"
"border-radius: 6px;\n"
"background-color: #116a06;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #22c70d, stop: 1 #116a06);\n"
"}"));
        depotButton = new QPushButton(centralWidget);
        depotButton->setObjectName(QStringLiteral("depotButton"));
        depotButton->setGeometry(QRect(370, 10, 93, 28));
        QPalette palette;
        QLinearGradient gradient(0, 0, 0, 0.67);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(34, 199, 13, 255));
        gradient.setColorAt(1, QColor(17, 106, 6, 255));
        QBrush brush(gradient);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QLinearGradient gradient1(0, 0, 0, 0.67);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(34, 199, 13, 255));
        gradient1.setColorAt(1, QColor(17, 106, 6, 255));
        QBrush brush1(gradient1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QLinearGradient gradient2(0, 0, 0, 0.67);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(34, 199, 13, 255));
        gradient2.setColorAt(1, QColor(17, 106, 6, 255));
        QBrush brush2(gradient2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        QLinearGradient gradient3(0, 0, 0, 0.67);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(34, 199, 13, 255));
        gradient3.setColorAt(1, QColor(17, 106, 6, 255));
        QBrush brush3(gradient3);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        QLinearGradient gradient4(0, 0, 0, 0.67);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(34, 199, 13, 255));
        gradient4.setColorAt(1, QColor(17, 106, 6, 255));
        QBrush brush4(gradient4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        QLinearGradient gradient5(0, 0, 0, 0.67);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(34, 199, 13, 255));
        gradient5.setColorAt(1, QColor(17, 106, 6, 255));
        QBrush brush5(gradient5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        QLinearGradient gradient6(0, 0, 0, 0.67);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(34, 199, 13, 255));
        gradient6.setColorAt(1, QColor(17, 106, 6, 255));
        QBrush brush6(gradient6);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        QLinearGradient gradient7(0, 0, 0, 0.67);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(34, 199, 13, 255));
        gradient7.setColorAt(1, QColor(17, 106, 6, 255));
        QBrush brush7(gradient7);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        QLinearGradient gradient8(0, 0, 0, 0.67);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(34, 199, 13, 255));
        gradient8.setColorAt(1, QColor(17, 106, 6, 255));
        QBrush brush8(gradient8);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        depotButton->setPalette(palette);
        depotButton->setStyleSheet(QLatin1String("QPushButton:pressed {\n"
"	background-color: #222222;\n"
"	border: 1px solid #333333;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #66db57;\n"
"}\n"
"QPushButton {\n"
"font: 75 12pt \"Caladea\";\n"
"border: 1px solid #199909;\n"
"border-radius: 6px;\n"
"background-color: #116a06;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #22c70d, stop: 1 #116a06);\n"
"}"));
        shopButton = new QPushButton(centralWidget);
        shopButton->setObjectName(QStringLiteral("shopButton"));
        shopButton->setGeometry(QRect(690, 10, 93, 28));
        shopButton->setStyleSheet(QLatin1String("QPushButton:pressed {\n"
"	background-color: #222222;\n"
"	border: 1px solid #333333;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #66db57;\n"
"}\n"
"QPushButton {\n"
"font: 75 12pt \"Caladea\";\n"
"border: 1px solid #199909;\n"
"border-radius: 6px;\n"
"background-color: #116a06;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #22c70d, stop: 1 #116a06);\n"
"}"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 101, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
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
        textEdit->setPlaceholderText(QApplication::translate("MainWindow", "-mit\303\244 korjataan?? hinta???", Q_NULLPTR));
        fixButton->setText(QApplication::translate("MainWindow", "Korjaa", Q_NULLPTR));
        directionButton->setText(QApplication::translate("MainWindow", "Suunta", Q_NULLPTR));
        directionLabel->setText(QApplication::translate("MainWindow", "Eteen", Q_NULLPTR));
        comingLabel->setText(QApplication::translate("MainWindow", "Tulevat", Q_NULLPTR));
        passedLabel->setText(QApplication::translate("MainWindow", "Menneet", Q_NULLPTR));
        buyButton->setText(QApplication::translate("MainWindow", "Osta", Q_NULLPTR));
        sellButton->setText(QApplication::translate("MainWindow", "Myy", Q_NULLPTR));
        playerTrainsLabel->setText(QApplication::translate("MainWindow", "Omat huoltojunat", Q_NULLPTR));
        buyableTrainsLabel->setText(QApplication::translate("MainWindow", "Ostettavat junat", Q_NULLPTR));
        setTrainButton->setText(QApplication::translate("MainWindow", "Valitse juna", Q_NULLPTR));
        gameButton->setText(QApplication::translate("MainWindow", "Pelaa", Q_NULLPTR));
        depotButton->setText(QApplication::translate("MainWindow", "Varikko", Q_NULLPTR));
        shopButton->setText(QApplication::translate("MainWindow", "Kauppa", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Fame/raha:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
