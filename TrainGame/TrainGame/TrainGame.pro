#-------------------------------------------------
#
# Project created by QtCreator 2017-09-25T12:37:27
#
#-------------------------------------------------

QT       += core gui network
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrainGame
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    game.cpp \
    raillogic.cpp \
    railtileinterface.cpp \
    onesiderailtile.cpp \
    playerlogic.cpp \
    traininterface.cpp \
    playertrain.cpp \
    obstaclelogic.cpp \
    obstacleinterface.cpp \
    boulder.cpp \
    datareader.cpp \
    shop.cpp \
    station.cpp \
    background.cpp \
    obstaclefactory.cpp \
    backgroundlogic.cpp \
    vrtrainmanager.cpp \
    vrtrain.cpp \
    httpengine.cpp \
    gameexception.cpp \
    ioexception.cpp \
    leafpile.cpp \
    pathfinder.cpp \
    endgame.cpp \
    startwindow.cpp


HEADERS += \
        mainwindow.h \
    game.h \
    raillogic.h \
    railtileinterface.h \
    onesiderailtile.h \
    playerlogic.h \
    traininterface.h \
    playertrain.h \
    obstaclelogic.h \
    obstacleinterface.h \
    boulder.h \
    datareader.h \
    shop.h \
    station.h \
    background.h \
    obstaclefactory.h \
    backgroundlogic.h \
    vrtrainmanager.h \
    vrtrain.h \
    httpengine.h \
    gameexception.h \
    ioexception.h \
    leafpile.h \
    pathfinder.h \
    endgame.h \
    startwindow.h


FORMS += \
        mainwindow.ui \
    endgame.ui \
    startwindow.ui

RESOURCES += \
    res.qrc

DISTFILES +=
