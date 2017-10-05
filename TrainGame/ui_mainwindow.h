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
#include <QtWidgets/QDateEdit>
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
    QDateEdit *dateEdit;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QWidget *pelaaPage;
    QGraphicsView *peliView;
    QGraphicsView *rautaTieKarttaView;
    QTextEdit *esteTextEdit;
    QTextEdit *infoTextEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSlider *kaasuSlider;
    QPushButton *suuntaButton;
    QLabel *suuntaLabel;
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
        stackedWidget->setGeometry(QRect(11, 55, 1131, 511));
        valikkoPage = new QWidget();
        valikkoPage->setObjectName(QStringLiteral("valikkoPage"));
        listView_3 = new QListView(valikkoPage);
        listView_3->setObjectName(QStringLiteral("listView_3"));
        listView_3->setGeometry(QRect(20, 20, 331, 481));
        textEdit = new QTextEdit(valikkoPage);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(773, 30, 321, 461));
        dateEdit = new QDateEdit(valikkoPage);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(510, 60, 112, 30));
        label_2 = new QLabel(valikkoPage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(510, 30, 111, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        pushButton_3 = new QPushButton(valikkoPage);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(360, 470, 111, 28));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton:pressed {\n"
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
        pushButton->setGeometry(QRect(850, 330, 93, 28));
        pushButton->setStyleSheet(QLatin1String("QPushButton:pressed {\n"
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
        pushButton_2 = new QPushButton(pelaaPage);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(1010, 330, 93, 28));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton:pressed {\n"
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
        kaasuSlider = new QSlider(pelaaPage);
        kaasuSlider->setObjectName(QStringLiteral("kaasuSlider"));
        kaasuSlider->setGeometry(QRect(1050, 390, 22, 101));
        kaasuSlider->setStyleSheet(QLatin1String("QSlider  \n"
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
        kaasuSlider->setOrientation(Qt::Vertical);
        suuntaButton = new QPushButton(pelaaPage);
        suuntaButton->setObjectName(QStringLiteral("suuntaButton"));
        suuntaButton->setGeometry(QRect(940, 390, 93, 28));
        suuntaButton->setStyleSheet(QLatin1String("QPushButton:pressed {\n"
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
        suuntaLabel = new QLabel(pelaaPage);
        suuntaLabel->setObjectName(QStringLiteral("suuntaLabel"));
        suuntaLabel->setGeometry(QRect(940, 430, 101, 31));
        suuntaLabel->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(pelaaPage);
        kauppaPage = new QWidget();
        kauppaPage->setObjectName(QStringLiteral("kauppaPage"));
        ostaButton = new QPushButton(kauppaPage);
        ostaButton->setObjectName(QStringLiteral("ostaButton"));
        ostaButton->setGeometry(QRect(500, 120, 141, 51));
        ostaButton->setStyleSheet(QLatin1String("QPushButton:pressed {\n"
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
        myyButton = new QPushButton(kauppaPage);
        myyButton->setObjectName(QStringLiteral("myyButton"));
        myyButton->setGeometry(QRect(500, 220, 141, 51));
        myyButton->setStyleSheet(QLatin1String("QPushButton:pressed {\n"
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
        label_4 = new QLabel(kauppaPage);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(24, 0, 301, 20));
        label_4->setStyleSheet(QStringLiteral("font: 75 14pt \"Caladea\";"));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(kauppaPage);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(794, 0, 321, 20));
        label_5->setStyleSheet(QStringLiteral("font: 75 14pt \"Caladea\";"));
        label_5->setAlignment(Qt::AlignCenter);
        listView = new QListView(kauppaPage);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(20, 40, 301, 261));
        listView_2 = new QListView(kauppaPage);
        listView_2->setObjectName(QStringLiteral("listView_2"));
        listView_2->setGeometry(QRect(795, 40, 321, 261));
        stackedWidget->addWidget(kauppaPage);
        peliButton = new QPushButton(centralWidget);
        peliButton->setObjectName(QStringLiteral("peliButton"));
        peliButton->setGeometry(QRect(530, 10, 93, 28));
        peliButton->setMouseTracking(false);
        peliButton->setStyleSheet(QLatin1String("QPushButton:pressed {\n"
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
        valikkoButton = new QPushButton(centralWidget);
        valikkoButton->setObjectName(QStringLiteral("valikkoButton"));
        valikkoButton->setGeometry(QRect(370, 10, 93, 28));
        QPalette palette;
        QBrush brush(QColor(113, 113, 113, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QLinearGradient gradient(0, 0, 0, 0.67);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(34, 199, 13, 255));
        gradient.setColorAt(1, QColor(17, 106, 6, 255));
        QBrush brush1(gradient);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QLinearGradient gradient1(0, 0, 0, 0.67);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(34, 199, 13, 255));
        gradient1.setColorAt(1, QColor(17, 106, 6, 255));
        QBrush brush2(gradient1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        QLinearGradient gradient2(0, 0, 0, 0.67);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(34, 199, 13, 255));
        gradient2.setColorAt(1, QColor(17, 106, 6, 255));
        QBrush brush3(gradient2);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        QLinearGradient gradient3(0, 0, 0, 0.67);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(34, 199, 13, 255));
        gradient3.setColorAt(1, QColor(17, 106, 6, 255));
        QBrush brush4(gradient3);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QLinearGradient gradient4(0, 0, 0, 0.67);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(34, 199, 13, 255));
        gradient4.setColorAt(1, QColor(17, 106, 6, 255));
        QBrush brush5(gradient4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        QLinearGradient gradient5(0, 0, 0, 0.67);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(34, 199, 13, 255));
        gradient5.setColorAt(1, QColor(17, 106, 6, 255));
        QBrush brush6(gradient5);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        valikkoButton->setPalette(palette);
        valikkoButton->setStyleSheet(QLatin1String("QPushButton:pressed {\n"
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
        kauppaButton = new QPushButton(centralWidget);
        kauppaButton->setObjectName(QStringLiteral("kauppaButton"));
        kauppaButton->setGeometry(QRect(690, 10, 93, 28));
        kauppaButton->setStyleSheet(QLatin1String("QPushButton:pressed {\n"
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

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "TrainGame", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "pelattava p\303\244iv\303\244", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "junakorjausBtn", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Vasen", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Oikea", Q_NULLPTR));
        suuntaButton->setText(QApplication::translate("MainWindow", "Suunta", Q_NULLPTR));
        suuntaLabel->setText(QApplication::translate("MainWindow", "Eteen", Q_NULLPTR));
        ostaButton->setText(QApplication::translate("MainWindow", "Osta", Q_NULLPTR));
        myyButton->setText(QApplication::translate("MainWindow", "Myy", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Omat huoltojunat", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Ostettavat junat", Q_NULLPTR));
        peliButton->setText(QApplication::translate("MainWindow", "Pelaa", Q_NULLPTR));
        valikkoButton->setText(QApplication::translate("MainWindow", "Valikko", Q_NULLPTR));
        kauppaButton->setText(QApplication::translate("MainWindow", "Kauppa", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Fame/raha:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
