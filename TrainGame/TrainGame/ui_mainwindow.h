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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *depotPage;
    QPushButton *fixButton;
    QListWidget *fixListWidget;
    QWidget *gamePage;
    QGraphicsView *gameView;
    QGraphicsView *minimapView;
    QSlider *gasSlider;
    QPushButton *directionButton;
    QLabel *directionLabel;
    QLabel *comingLabel;
    QLabel *passedLabel;
    QListWidget *nextStationsListWidget;
    QListWidget *passedStationsListWidget;
    QLabel *latestPassedLabel;
    QLabel *label_2;
    QWidget *shopPage;
    QPushButton *buyButton;
    QPushButton *sellButton;
    QLabel *playerTrainsLabel;
    QLabel *buyableTrainsLabel;
    QListWidget *buyableTrainsListWidget;
    QListWidget *ownedTrainsListWidget;
    QLabel *valitseJunaLabel;
    QLabel *costsLabelText;
    QPushButton *confirmButton;
    QLabel *featuresTextOLabel;
    QLabel *featuresTextBLabel;
    QLabel *featuresOLabel;
    QLabel *featuresBLabel;
    QLabel *costsLabel;
    QPushButton *gameButton;
    QPushButton *depotButton;
    QPushButton *shopButton;
    QLabel *fameTextLabel;
    QLabel *fameLabel;
    QLabel *moneyTextLabel;
    QLabel *label_4;
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
        fixButton = new QPushButton(depotPage);
        fixButton->setObjectName(QStringLiteral("fixButton"));
        fixButton->setGeometry(QRect(880, 250, 111, 28));
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
        fixListWidget = new QListWidget(depotPage);
        fixListWidget->setObjectName(QStringLiteral("fixListWidget"));
        fixListWidget->setGeometry(QRect(30, 50, 811, 441));
        QFont font;
        font.setPointSize(15);
        fixListWidget->setFont(font);
        stackedWidget->addWidget(depotPage);
        gamePage = new QWidget();
        gamePage->setObjectName(QStringLiteral("gamePage"));
        gameView = new QGraphicsView(gamePage);
        gameView->setObjectName(QStringLiteral("gameView"));
        gameView->setGeometry(QRect(310, 10, 511, 481));
        minimapView = new QGraphicsView(gamePage);
        minimapView->setObjectName(QStringLiteral("minimapView"));
        minimapView->setGeometry(QRect(10, 70, 281, 421));
        gasSlider = new QSlider(gamePage);
        gasSlider->setObjectName(QStringLiteral("gasSlider"));
        gasSlider->setGeometry(QRect(860, 450, 251, 41));
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
        gasSlider->setMaximum(200);
        gasSlider->setSliderPosition(0);
        gasSlider->setOrientation(Qt::Horizontal);
        directionButton = new QPushButton(gamePage);
        directionButton->setObjectName(QStringLiteral("directionButton"));
        directionButton->setGeometry(QRect(870, 410, 71, 31));
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
        directionLabel->setGeometry(QRect(950, 410, 61, 21));
        directionLabel->setAlignment(Qt::AlignCenter);
        comingLabel = new QLabel(gamePage);
        comingLabel->setObjectName(QStringLiteral("comingLabel"));
        comingLabel->setGeometry(QRect(950, 0, 81, 16));
        passedLabel = new QLabel(gamePage);
        passedLabel->setObjectName(QStringLiteral("passedLabel"));
        passedLabel->setGeometry(QRect(960, 200, 71, 16));
        nextStationsListWidget = new QListWidget(gamePage);
        nextStationsListWidget->setObjectName(QStringLiteral("nextStationsListWidget"));
        nextStationsListWidget->setGeometry(QRect(860, 20, 261, 171));
        passedStationsListWidget = new QListWidget(gamePage);
        passedStationsListWidget->setObjectName(QStringLiteral("passedStationsListWidget"));
        passedStationsListWidget->setGeometry(QRect(860, 220, 261, 171));
        latestPassedLabel = new QLabel(gamePage);
        latestPassedLabel->setObjectName(QStringLiteral("latestPassedLabel"));
        latestPassedLabel->setGeometry(QRect(50, 0, 201, 16));
        QFont font1;
        font1.setPointSize(11);
        latestPassedLabel->setFont(font1);
        label_2 = new QLabel(gamePage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 30, 181, 20));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(gamePage);
        shopPage = new QWidget();
        shopPage->setObjectName(QStringLiteral("shopPage"));
        buyButton = new QPushButton(shopPage);
        buyButton->setObjectName(QStringLiteral("buyButton"));
        buyButton->setGeometry(QRect(600, 250, 141, 51));
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
        sellButton->setGeometry(QRect(370, 250, 141, 51));
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
        playerTrainsLabel->setGeometry(QRect(30, 10, 251, 31));
        playerTrainsLabel->setStyleSheet(QStringLiteral("font: 75 14pt \"Caladea\";"));
        playerTrainsLabel->setAlignment(Qt::AlignCenter);
        buyableTrainsLabel = new QLabel(shopPage);
        buyableTrainsLabel->setObjectName(QStringLiteral("buyableTrainsLabel"));
        buyableTrainsLabel->setGeometry(QRect(840, 10, 261, 31));
        buyableTrainsLabel->setStyleSheet(QStringLiteral("font: 75 14pt \"Caladea\";"));
        buyableTrainsLabel->setAlignment(Qt::AlignCenter);
        buyableTrainsListWidget = new QListWidget(shopPage);
        buyableTrainsListWidget->setObjectName(QStringLiteral("buyableTrainsListWidget"));
        buyableTrainsListWidget->setGeometry(QRect(835, 60, 271, 351));
        buyableTrainsListWidget->setFont(font);
        ownedTrainsListWidget = new QListWidget(shopPage);
        ownedTrainsListWidget->setObjectName(QStringLiteral("ownedTrainsListWidget"));
        ownedTrainsListWidget->setGeometry(QRect(30, 60, 251, 341));
        ownedTrainsListWidget->setFont(font);
        valitseJunaLabel = new QLabel(shopPage);
        valitseJunaLabel->setObjectName(QStringLiteral("valitseJunaLabel"));
        valitseJunaLabel->setGeometry(QRect(460, 60, 181, 20));
        QFont font2;
        font2.setPointSize(10);
        valitseJunaLabel->setFont(font2);
        valitseJunaLabel->setAlignment(Qt::AlignCenter);
        costsLabelText = new QLabel(shopPage);
        costsLabelText->setObjectName(QStringLiteral("costsLabelText"));
        costsLabelText->setGeometry(QRect(420, 360, 181, 61));
        QFont font3;
        font3.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font3.setPointSize(15);
        costsLabelText->setFont(font3);
        confirmButton = new QPushButton(shopPage);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        confirmButton->setGeometry(QRect(490, 100, 131, 51));
        confirmButton->setStyleSheet(QLatin1String("QPushButton:pressed {\n"
"	background-color: #000080;\n"
"	border: 1px solid #333333;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #add8e6;\n"
"}\n"
"QPushButton {\n"
"font: 75 15pt \"Caladea\";\n"
"border: 1px solid #199909;\n"
"border-radius: 6px;\n"
"background-color: #0000ff;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #0000ff, stop: 1 #0000ff);\n"
"}\n"
""));
        featuresTextOLabel = new QLabel(shopPage);
        featuresTextOLabel->setObjectName(QStringLiteral("featuresTextOLabel"));
        featuresTextOLabel->setGeometry(QRect(30, 440, 111, 21));
        QFont font4;
        font4.setBold(true);
        font4.setWeight(75);
        featuresTextOLabel->setFont(font4);
        featuresTextBLabel = new QLabel(shopPage);
        featuresTextBLabel->setObjectName(QStringLiteral("featuresTextBLabel"));
        featuresTextBLabel->setGeometry(QRect(790, 430, 111, 31));
        featuresOLabel = new QLabel(shopPage);
        featuresOLabel->setObjectName(QStringLiteral("featuresOLabel"));
        featuresOLabel->setGeometry(QRect(134, 440, 171, 20));
        featuresBLabel = new QLabel(shopPage);
        featuresBLabel->setObjectName(QStringLiteral("featuresBLabel"));
        featuresBLabel->setGeometry(QRect(944, 440, 161, 20));
        costsLabel = new QLabel(shopPage);
        costsLabel->setObjectName(QStringLiteral("costsLabel"));
        costsLabel->setGeometry(QRect(610, 370, 131, 41));
        costsLabel->setFont(font);
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
        fameTextLabel = new QLabel(centralWidget);
        fameTextLabel->setObjectName(QStringLiteral("fameTextLabel"));
        fameTextLabel->setGeometry(QRect(20, 10, 61, 20));
        QFont font5;
        font5.setPointSize(11);
        font5.setBold(false);
        font5.setWeight(50);
        fameTextLabel->setFont(font5);
        fameTextLabel->setAlignment(Qt::AlignCenter);
        fameLabel = new QLabel(centralWidget);
        fameLabel->setObjectName(QStringLiteral("fameLabel"));
        fameLabel->setGeometry(QRect(80, 10, 81, 21));
        fameLabel->setFont(font2);
        moneyTextLabel = new QLabel(centralWidget);
        moneyTextLabel->setObjectName(QStringLiteral("moneyTextLabel"));
        moneyTextLabel->setGeometry(QRect(160, 10, 41, 21));
        moneyTextLabel->setFont(font1);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(210, 10, 91, 21));
        label_4->setFont(font2);
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

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "TrainGame", Q_NULLPTR));
        fixButton->setText(QApplication::translate("MainWindow", "Korjaa", Q_NULLPTR));
        directionButton->setText(QApplication::translate("MainWindow", "Suunta", Q_NULLPTR));
        directionLabel->setText(QApplication::translate("MainWindow", "Eteen", Q_NULLPTR));
        comingLabel->setText(QApplication::translate("MainWindow", "Seuraavalta", Q_NULLPTR));
        passedLabel->setText(QApplication::translate("MainWindow", "Edelliselt\303\244", Q_NULLPTR));
        latestPassedLabel->setText(QApplication::translate("MainWindow", "Viimeisin ohitettu asema:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "ei ohitettuja asemia", Q_NULLPTR));
        buyButton->setText(QApplication::translate("MainWindow", "Osta", Q_NULLPTR));
        sellButton->setText(QApplication::translate("MainWindow", "Myy", Q_NULLPTR));
        playerTrainsLabel->setText(QApplication::translate("MainWindow", "Omat huoltojunat", Q_NULLPTR));
        buyableTrainsLabel->setText(QApplication::translate("MainWindow", "Ostettavat junat", Q_NULLPTR));
        valitseJunaLabel->setText(QApplication::translate("MainWindow", "Valitse k\303\244ytett\303\244v\303\244 juna", Q_NULLPTR));
        costsLabelText->setText(QApplication::translate("MainWindow", "Saat / Maksaa:", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("MainWindow", "Hyv\303\244ksy", Q_NULLPTR));
        featuresTextOLabel->setText(QApplication::translate("MainWindow", "Aktiivinen Juna:", Q_NULLPTR));
        featuresTextBLabel->setText(QApplication::translate("MainWindow", "Ominaisuudet:", Q_NULLPTR));
        featuresOLabel->setText(QString());
        featuresBLabel->setText(QString());
        costsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        gameButton->setText(QApplication::translate("MainWindow", "Pelaa", Q_NULLPTR));
        depotButton->setText(QApplication::translate("MainWindow", "Varikko", Q_NULLPTR));
        shopButton->setText(QApplication::translate("MainWindow", "Kauppa", Q_NULLPTR));
        fameTextLabel->setText(QApplication::translate("MainWindow", "fame:", Q_NULLPTR));
        fameLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        moneyTextLabel->setText(QApplication::translate("MainWindow", "raha:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
