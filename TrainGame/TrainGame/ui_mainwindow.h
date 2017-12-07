/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
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
    QLabel *label;
    QLabel *label_2;
    QLabel *currShape;
    QLabel *optimalShape;
    QLabel *label_3;
    QLabel *repairCostLabel;
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
    QLabel *nextStationLabel;
    QLabel *nextStation;
    QLabel *previousStationLabel;
    QLabel *previousStation;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *blockLocation;
    QLabel *blockTrack;
    QLabel *blockThreat;
    QLabel *label_8;
    QLabel *notificationLabel;
    QLabel *label_4;
    QLabel *naviLabel;
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
    QLabel *moneyLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1154, 642);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1154, 642));
        MainWindow->setMaximumSize(QSize(1154, 642));
        MainWindow->setStyleSheet(QStringLiteral("		background-color: 	#a32020;"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 40, 1131, 511));
        depotPage = new QWidget();
        depotPage->setObjectName(QStringLiteral("depotPage"));
        fixButton = new QPushButton(depotPage);
        fixButton->setObjectName(QStringLiteral("fixButton"));
        fixButton->setGeometry(QRect(850, 250, 111, 28));
        fixButton->setStyleSheet(QLatin1String("QPushButton:pressed {\n"
"	background-color: #222222;\n"
"	\n"
"}\n"
"QPushButton:hover {\n"
"		background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #a9d8f5, stop: 1 #52b7fa);\n"
"}\n"
"QPushButton {\n"
"font: 75 12pt \"Caladea\";\n"
"color: #fff;\n"
"border-radius: 8px;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #08f0f0, stop: 1 #009dff);\n"
"}"));
        fixListWidget = new QListWidget(depotPage);
        fixListWidget->setObjectName(QStringLiteral("fixListWidget"));
        fixListWidget->setGeometry(QRect(30, 50, 811, 441));
        QFont font;
        font.setPointSize(15);
        fixListWidget->setFont(font);
        fixListWidget->setStyleSheet(QLatin1String("QListWidget{\n"
"	border: 1px solid #52b7fa;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QListView::item{\n"
"	color: #fff;\n"
"}\n"
"QListWidget::item:selected\n"
"{\n"
"    		background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #a9d8f5, stop: 1 #52b7fa);\n"
"}"));
        label = new QLabel(depotPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(850, 50, 111, 20));
        label->setStyleSheet(QStringLiteral("color: #fff;"));
        label_2 = new QLabel(depotPage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(850, 90, 101, 20));
        label_2->setStyleSheet(QStringLiteral("color: #fff;"));
        currShape = new QLabel(depotPage);
        currShape->setObjectName(QStringLiteral("currShape"));
        currShape->setGeometry(QRect(970, 50, 141, 20));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        currShape->setFont(font1);
        currShape->setStyleSheet(QStringLiteral("color: #fff;"));
        optimalShape = new QLabel(depotPage);
        optimalShape->setObjectName(QStringLiteral("optimalShape"));
        optimalShape->setGeometry(QRect(970, 90, 141, 20));
        optimalShape->setFont(font1);
        optimalShape->setStyleSheet(QStringLiteral("color: #fff;"));
        label_3 = new QLabel(depotPage);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(850, 170, 111, 20));
        label_3->setStyleSheet(QStringLiteral("color: #fff;"));
        repairCostLabel = new QLabel(depotPage);
        repairCostLabel->setObjectName(QStringLiteral("repairCostLabel"));
        repairCostLabel->setGeometry(QRect(970, 170, 131, 20));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        repairCostLabel->setFont(font2);
        repairCostLabel->setStyleSheet(QStringLiteral("color: #fff;"));
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
        gasSlider->setGeometry(QRect(840, 470, 251, 41));
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
        gasSlider->setMaximum(10);
        gasSlider->setSliderPosition(0);
        gasSlider->setOrientation(Qt::Horizontal);
        directionButton = new QPushButton(gamePage);
        directionButton->setObjectName(QStringLiteral("directionButton"));
        directionButton->setGeometry(QRect(850, 430, 71, 31));
        directionButton->setStyleSheet(QLatin1String("QPushButton:hover {\n"
"	background-color: #ccc5c7;\n"
"}\n"
"QPushButton {\n"
"font: 75 12pt \"Caladea\";\n"
"color: #fff;\n"
"border: 1px solid #72595e;\n"
"border-radius: 6px;\n"
"background-color: #605053;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #bdbabb, stop: 1 #605053);\n"
"}"));
        directionLabel = new QLabel(gamePage);
        directionLabel->setObjectName(QStringLiteral("directionLabel"));
        directionLabel->setGeometry(QRect(940, 430, 61, 31));
        directionLabel->setStyleSheet(QStringLiteral("color: #fff;"));
        directionLabel->setAlignment(Qt::AlignCenter);
        comingLabel = new QLabel(gamePage);
        comingLabel->setObjectName(QStringLiteral("comingLabel"));
        comingLabel->setGeometry(QRect(840, 130, 81, 16));
        comingLabel->setStyleSheet(QStringLiteral("color: #fff;"));
        passedLabel = new QLabel(gamePage);
        passedLabel->setObjectName(QStringLiteral("passedLabel"));
        passedLabel->setGeometry(QRect(840, 280, 71, 16));
        passedLabel->setStyleSheet(QStringLiteral("color: #fff;"));
        nextStationsListWidget = new QListWidget(gamePage);
        nextStationsListWidget->setObjectName(QStringLiteral("nextStationsListWidget"));
        nextStationsListWidget->setGeometry(QRect(840, 150, 181, 131));
        nextStationsListWidget->setStyleSheet(QLatin1String("QListWidget{\n"
"	border: 1px solid #52b7fa;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QListView::item{\n"
"	color: #fff;\n"
"}\n"
"QListWidget::item:selected\n"
"{\n"
"    		background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #a9d8f5, stop: 1 #52b7fa);\n"
"}"));
        passedStationsListWidget = new QListWidget(gamePage);
        passedStationsListWidget->setObjectName(QStringLiteral("passedStationsListWidget"));
        passedStationsListWidget->setGeometry(QRect(840, 300, 181, 131));
        passedStationsListWidget->setStyleSheet(QLatin1String("QListWidget{\n"
"	border: 1px solid #52b7fa;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QListView::item{\n"
"	color: #fff;\n"
"}\n"
"QListWidget::item:selected\n"
"{\n"
"    		background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #a9d8f5, stop: 1 #52b7fa);\n"
"}"));
        nextStationLabel = new QLabel(gamePage);
        nextStationLabel->setObjectName(QStringLiteral("nextStationLabel"));
        nextStationLabel->setGeometry(QRect(0, 0, 121, 16));
        QFont font3;
        font3.setPointSize(11);
        nextStationLabel->setFont(font3);
        nextStationLabel->setStyleSheet(QStringLiteral("color: #fff;"));
        nextStation = new QLabel(gamePage);
        nextStation->setObjectName(QStringLiteral("nextStation"));
        nextStation->setGeometry(QRect(120, 0, 141, 20));
        nextStation->setFont(font3);
        nextStation->setStyleSheet(QStringLiteral("color: #fff;"));
        nextStation->setAlignment(Qt::AlignCenter);
        previousStationLabel = new QLabel(gamePage);
        previousStationLabel->setObjectName(QStringLiteral("previousStationLabel"));
        previousStationLabel->setGeometry(QRect(0, 20, 121, 16));
        previousStationLabel->setFont(font3);
        previousStationLabel->setStyleSheet(QStringLiteral("color: #fff;"));
        previousStation = new QLabel(gamePage);
        previousStation->setObjectName(QStringLiteral("previousStation"));
        previousStation->setGeometry(QRect(120, 20, 141, 20));
        previousStation->setFont(font3);
        previousStation->setStyleSheet(QStringLiteral("color: #fff;"));
        previousStation->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(gamePage);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(830, 10, 101, 17));
        label_5->setStyleSheet(QStringLiteral("color: #fff;"));
        label_6 = new QLabel(gamePage);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(830, 30, 64, 17));
        label_6->setStyleSheet(QStringLiteral("color: #fff;"));
        label_7 = new QLabel(gamePage);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(830, 50, 91, 17));
        label_7->setStyleSheet(QStringLiteral("color: #fff;"));
        blockLocation = new QLabel(gamePage);
        blockLocation->setObjectName(QStringLiteral("blockLocation"));
        blockLocation->setGeometry(QRect(930, 10, 211, 17));
        blockLocation->setStyleSheet(QStringLiteral("color: #fff;"));
        blockTrack = new QLabel(gamePage);
        blockTrack->setObjectName(QStringLiteral("blockTrack"));
        blockTrack->setGeometry(QRect(930, 30, 191, 17));
        blockTrack->setStyleSheet(QStringLiteral("color: #fff;"));
        blockThreat = new QLabel(gamePage);
        blockThreat->setObjectName(QStringLiteral("blockThreat"));
        blockThreat->setGeometry(QRect(930, 50, 201, 17));
        blockThreat->setStyleSheet(QStringLiteral("color: #fff;"));
        label_8 = new QLabel(gamePage);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(830, 80, 121, 17));
        label_8->setStyleSheet(QStringLiteral("color: #fff;"));
        notificationLabel = new QLabel(gamePage);
        notificationLabel->setObjectName(QStringLiteral("notificationLabel"));
        notificationLabel->setGeometry(QRect(950, 80, 181, 16));
        notificationLabel->setStyleSheet(QStringLiteral("color: #fff;"));
        label_4 = new QLabel(gamePage);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(830, 100, 31, 17));
        label_4->setStyleSheet(QStringLiteral("color: #fff;"));
        naviLabel = new QLabel(gamePage);
        naviLabel->setObjectName(QStringLiteral("naviLabel"));
        naviLabel->setGeometry(QRect(870, 100, 271, 20));
        naviLabel->setStyleSheet(QStringLiteral("color: #fff;"));
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
"color: #fff;\n"
"border: 1px solid #199909;\n"
"border-radius: 10px;\n"
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
"color: #fff;\n"
"border-radius: 10px;\n"
"background-color: #ea0533;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #fb2953, stop: 1 #c90029);\n"
"}"));
        playerTrainsLabel = new QLabel(shopPage);
        playerTrainsLabel->setObjectName(QStringLiteral("playerTrainsLabel"));
        playerTrainsLabel->setGeometry(QRect(30, 10, 251, 31));
        playerTrainsLabel->setStyleSheet(QLatin1String("font: 75 14pt \"Caladea\";\n"
"color: #fff;"));
        playerTrainsLabel->setAlignment(Qt::AlignCenter);
        buyableTrainsLabel = new QLabel(shopPage);
        buyableTrainsLabel->setObjectName(QStringLiteral("buyableTrainsLabel"));
        buyableTrainsLabel->setGeometry(QRect(840, 10, 261, 31));
        buyableTrainsLabel->setStyleSheet(QLatin1String("font: 75 14pt \"Caladea\";\n"
"color: #fff;"));
        buyableTrainsLabel->setAlignment(Qt::AlignCenter);
        buyableTrainsListWidget = new QListWidget(shopPage);
        buyableTrainsListWidget->setObjectName(QStringLiteral("buyableTrainsListWidget"));
        buyableTrainsListWidget->setGeometry(QRect(835, 60, 271, 351));
        buyableTrainsListWidget->setFont(font);
        buyableTrainsListWidget->setStyleSheet(QLatin1String("QListWidget{\n"
"	border: 1px solid #52b7fa;\n"
"	border-radius: 5px;\n"
"}\n"
"QListView::item{\n"
"	color: #fff;\n"
"}\n"
"QListWidget::item:selected\n"
"{\n"
"    		background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #a9d8f5, stop: 1 #52b7fa);\n"
"}"));
        ownedTrainsListWidget = new QListWidget(shopPage);
        ownedTrainsListWidget->setObjectName(QStringLiteral("ownedTrainsListWidget"));
        ownedTrainsListWidget->setGeometry(QRect(30, 60, 251, 341));
        ownedTrainsListWidget->setFont(font);
        ownedTrainsListWidget->setStyleSheet(QLatin1String("QListWidget{\n"
"	border: 1px solid #52b7fa;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QListView::item{\n"
"	color: #fff;\n"
"}\n"
"QListWidget::item:selected\n"
"{\n"
"    		background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #a9d8f5, stop: 1 #52b7fa);\n"
"}"));
        valitseJunaLabel = new QLabel(shopPage);
        valitseJunaLabel->setObjectName(QStringLiteral("valitseJunaLabel"));
        valitseJunaLabel->setGeometry(QRect(460, 60, 181, 20));
        QFont font4;
        font4.setPointSize(10);
        valitseJunaLabel->setFont(font4);
        valitseJunaLabel->setStyleSheet(QStringLiteral("color: #fff;"));
        valitseJunaLabel->setAlignment(Qt::AlignCenter);
        costsLabelText = new QLabel(shopPage);
        costsLabelText->setObjectName(QStringLiteral("costsLabelText"));
        costsLabelText->setGeometry(QRect(420, 360, 181, 61));
        QFont font5;
        font5.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font5.setPointSize(15);
        costsLabelText->setFont(font5);
        costsLabelText->setStyleSheet(QStringLiteral("color: #fff;"));
        confirmButton = new QPushButton(shopPage);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        confirmButton->setGeometry(QRect(470, 100, 161, 51));
        confirmButton->setStyleSheet(QLatin1String("QPushButton:hover {\n"
"	background-color: #ccc5c7;\n"
"}\n"
"QPushButton {\n"
"font: 75 12pt \"Caladea\";\n"
"color: #fff;\n"
"border: 1px solid #72595e;\n"
"border-radius: 10px;\n"
"background-color: #605053;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #bdbabb, stop: 1 #605053);\n"
"}\n"
""));
        featuresTextOLabel = new QLabel(shopPage);
        featuresTextOLabel->setObjectName(QStringLiteral("featuresTextOLabel"));
        featuresTextOLabel->setGeometry(QRect(30, 440, 111, 21));
        QFont font6;
        font6.setBold(true);
        font6.setWeight(75);
        featuresTextOLabel->setFont(font6);
        featuresTextOLabel->setStyleSheet(QStringLiteral("color: #fff;"));
        featuresTextBLabel = new QLabel(shopPage);
        featuresTextBLabel->setObjectName(QStringLiteral("featuresTextBLabel"));
        featuresTextBLabel->setGeometry(QRect(790, 430, 111, 31));
        featuresTextBLabel->setStyleSheet(QStringLiteral("color: #fff;"));
        featuresOLabel = new QLabel(shopPage);
        featuresOLabel->setObjectName(QStringLiteral("featuresOLabel"));
        featuresOLabel->setGeometry(QRect(150, 440, 171, 20));
        featuresOLabel->setStyleSheet(QStringLiteral("color: #fff;"));
        featuresBLabel = new QLabel(shopPage);
        featuresBLabel->setObjectName(QStringLiteral("featuresBLabel"));
        featuresBLabel->setGeometry(QRect(930, 429, 161, 31));
        featuresBLabel->setStyleSheet(QStringLiteral("color: #fff;"));
        costsLabel = new QLabel(shopPage);
        costsLabel->setObjectName(QStringLiteral("costsLabel"));
        costsLabel->setGeometry(QRect(610, 370, 131, 41));
        costsLabel->setFont(font);
        costsLabel->setStyleSheet(QStringLiteral("color: #fff;"));
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
"		background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #a9d8f5, stop: 1 #52b7fa);\n"
"}\n"
"QPushButton {\n"
"font: 75 12pt \"Caladea\";\n"
"color: #fff;\n"
"border-radius: 8px;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #08f0f0, stop: 1 #009dff);\n"
"}"));
        depotButton = new QPushButton(centralWidget);
        depotButton->setObjectName(QStringLiteral("depotButton"));
        depotButton->setGeometry(QRect(370, 10, 93, 28));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient(0, 0, 0, 0.67);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(8, 240, 240, 255));
        gradient.setColorAt(1, QColor(0, 157, 255, 255));
        QBrush brush1(gradient);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient1(0, 0, 0, 0.67);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(8, 240, 240, 255));
        gradient1.setColorAt(1, QColor(0, 157, 255, 255));
        QBrush brush2(gradient1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QLinearGradient gradient2(0, 0, 0, 0.67);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(8, 240, 240, 255));
        gradient2.setColorAt(1, QColor(0, 157, 255, 255));
        QBrush brush3(gradient2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient3(0, 0, 0, 0.67);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(8, 240, 240, 255));
        gradient3.setColorAt(1, QColor(0, 157, 255, 255));
        QBrush brush4(gradient3);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient4(0, 0, 0, 0.67);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(8, 240, 240, 255));
        gradient4.setColorAt(1, QColor(0, 157, 255, 255));
        QBrush brush5(gradient4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        QLinearGradient gradient5(0, 0, 0, 0.67);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(8, 240, 240, 255));
        gradient5.setColorAt(1, QColor(0, 157, 255, 255));
        QBrush brush6(gradient5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient6(0, 0, 0, 0.67);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(8, 240, 240, 255));
        gradient6.setColorAt(1, QColor(0, 157, 255, 255));
        QBrush brush7(gradient6);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient7(0, 0, 0, 0.67);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(8, 240, 240, 255));
        gradient7.setColorAt(1, QColor(0, 157, 255, 255));
        QBrush brush8(gradient7);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        QLinearGradient gradient8(0, 0, 0, 0.67);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(8, 240, 240, 255));
        gradient8.setColorAt(1, QColor(0, 157, 255, 255));
        QBrush brush9(gradient8);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        depotButton->setPalette(palette);
        depotButton->setStyleSheet(QLatin1String("QPushButton:pressed {\n"
"	background-color: #222222;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #a9d8f5, stop: 1 #52b7fa);\n"
"}\n"
"QPushButton {\n"
"font: 75 12pt \"Caladea\";\n"
"color: #fff;\n"
"border-radius: 8px;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #08f0f0, stop: 1 #009dff);\n"
"}"));
        shopButton = new QPushButton(centralWidget);
        shopButton->setObjectName(QStringLiteral("shopButton"));
        shopButton->setGeometry(QRect(690, 10, 93, 28));
        shopButton->setStyleSheet(QLatin1String("QPushButton:pressed {\n"
"	background-color: #222222;\n"
"	\n"
"}\n"
"QPushButton:hover {\n"
"		background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #a9d8f5, stop: 1 #52b7fa);\n"
"}\n"
"QPushButton {\n"
"font: 75 12pt \"Caladea\";\n"
"color: #fff;\n"
"border-radius: 8px;\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, \n"
"            stop: 0 #08f0f0, stop: 1 #009dff);\n"
"}"));
        fameTextLabel = new QLabel(centralWidget);
        fameTextLabel->setObjectName(QStringLiteral("fameTextLabel"));
        fameTextLabel->setGeometry(QRect(20, 10, 61, 20));
        QFont font7;
        font7.setPointSize(11);
        font7.setBold(false);
        font7.setWeight(50);
        fameTextLabel->setFont(font7);
        fameTextLabel->setStyleSheet(QStringLiteral("color: #fff;"));
        fameTextLabel->setAlignment(Qt::AlignCenter);
        fameLabel = new QLabel(centralWidget);
        fameLabel->setObjectName(QStringLiteral("fameLabel"));
        fameLabel->setGeometry(QRect(80, 10, 81, 21));
        fameLabel->setFont(font4);
        fameLabel->setStyleSheet(QStringLiteral("color: #fff;"));
        moneyTextLabel = new QLabel(centralWidget);
        moneyTextLabel->setObjectName(QStringLiteral("moneyTextLabel"));
        moneyTextLabel->setGeometry(QRect(160, 10, 41, 21));
        moneyTextLabel->setFont(font3);
        moneyTextLabel->setStyleSheet(QStringLiteral("color: #fff;"));
        moneyLabel = new QLabel(centralWidget);
        moneyLabel->setObjectName(QStringLiteral("moneyLabel"));
        moneyLabel->setGeometry(QRect(210, 10, 91, 21));
        moneyLabel->setFont(font4);
        moneyLabel->setStyleSheet(QStringLiteral("color: #fff;"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "TrainGame", 0));
        fixButton->setText(QApplication::translate("MainWindow", "Korjaa", 0));
        label->setText(QApplication::translate("MainWindow", "Nykyinen kunto:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Optimi kunto:", 0));
        currShape->setText(QString());
        optimalShape->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Korjaus maksaa:", 0));
        repairCostLabel->setText(QString());
        directionButton->setText(QApplication::translate("MainWindow", "Suunta", 0));
        directionLabel->setText(QApplication::translate("MainWindow", "Eteen", 0));
        comingLabel->setText(QApplication::translate("MainWindow", "Seuraavalta", 0));
        passedLabel->setText(QApplication::translate("MainWindow", "Edelliselt\303\244", 0));
        nextStationLabel->setText(QApplication::translate("MainWindow", "Seuraava asema:", 0));
        nextStation->setText(QApplication::translate("MainWindow", "?", 0));
        previousStationLabel->setText(QApplication::translate("MainWindow", "Edellinen asema:", 0));
        previousStation->setText(QApplication::translate("MainWindow", "?", 0));
        label_5->setText(QApplication::translate("MainWindow", "Esteen sijainti:", 0));
        label_6->setText(QApplication::translate("MainWindow", "Raiteella:", 0));
        label_7->setText(QApplication::translate("MainWindow", "Haittataso:", 0));
        blockLocation->setText(QApplication::translate("MainWindow", "asd", 0));
        blockTrack->setText(QApplication::translate("MainWindow", "asd", 0));
        blockThreat->setText(QApplication::translate("MainWindow", "asd", 0));
        label_8->setText(QApplication::translate("MainWindow", "Viimeisin ilmoitus:", 0));
        notificationLabel->setText(QApplication::translate("MainWindow", "-", 0));
        label_4->setText(QApplication::translate("MainWindow", "Navi: ", 0));
        naviLabel->setText(QApplication::translate("MainWindow", "-", 0));
        buyButton->setText(QApplication::translate("MainWindow", "Osta", 0));
        sellButton->setText(QApplication::translate("MainWindow", "Myy", 0));
        playerTrainsLabel->setText(QApplication::translate("MainWindow", "Omat huoltojunat", 0));
        buyableTrainsLabel->setText(QApplication::translate("MainWindow", "Ostettavat junat", 0));
        valitseJunaLabel->setText(QApplication::translate("MainWindow", "Valitse k\303\244ytett\303\244v\303\244 juna", 0));
        costsLabelText->setText(QApplication::translate("MainWindow", "Saat / Maksaa:", 0));
        confirmButton->setText(QApplication::translate("MainWindow", "Aseta aktiiviseksi", 0));
        featuresTextOLabel->setText(QApplication::translate("MainWindow", "Aktiivinen Juna:", 0));
        featuresTextBLabel->setText(QApplication::translate("MainWindow", "Ominaisuudet:", 0));
        featuresOLabel->setText(QString());
        featuresBLabel->setText(QString());
        costsLabel->setText(QApplication::translate("MainWindow", "0", 0));
        gameButton->setText(QApplication::translate("MainWindow", "Pelaa", 0));
        depotButton->setText(QApplication::translate("MainWindow", "Varikko", 0));
        shopButton->setText(QApplication::translate("MainWindow", "Kauppa", 0));
        fameTextLabel->setText(QApplication::translate("MainWindow", "fame:", 0));
        fameLabel->setText(QApplication::translate("MainWindow", "0", 0));
        moneyTextLabel->setText(QApplication::translate("MainWindow", "raha:", 0));
        moneyLabel->setText(QApplication::translate("MainWindow", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
