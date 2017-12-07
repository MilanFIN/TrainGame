#-------------------------------------------------
#
# Project created by QtCreator 2017-10-13T13:41:01
#
#-------------------------------------------------

QT       += testlib
QT       += widgets
QT       += network
TARGET = test
CONFIG   += console
CONFIG   -= app_bundle

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
        ../TrainGame/mainwindow.cpp \
        ../TrainGame/game.cpp \
        ../TrainGame/raillogic.cpp \
        ../TrainGame/railtileinterface.cpp \
        ../TrainGame/onesiderailtile.cpp \
        ../TrainGame/playerlogic.cpp \
        ../TrainGame/traininterface.cpp \
        ../TrainGame/playertrain.cpp \
        ../TrainGame/obstaclelogic.cpp \
        ../TrainGame/obstacleinterface.cpp \
        ../TrainGame/boulder.cpp \
        ../TrainGame/datareader.cpp \
        ../TrainGame/shop.cpp \
        ../TrainGame/station.cpp \
        ../TrainGame/background.cpp \
        ../TrainGame/obstaclefactory.cpp \
        ../TrainGame/backgroundlogic.cpp \
        ../TrainGame/vrtrain.cpp \
        ../TrainGame/vrtrainmanager.cpp \
        ../TrainGame/httpengine.cpp \
        ../TrainGame/gameexception.cpp \
        ../TrainGame/ioexception.cpp \
        ../TrainGame/leafpile.cpp \
        ../TrainGame/pathfinder.cpp \
        ../TrainGame/endgame.cpp \
        ../TrainGame/startwindow.cpp \
    main.cpp \
    testbackground.cpp \
    testgame.cpp \
    testboulder.cpp \
    testplayerlogic.cpp \
    testbackgroundlogic.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
        ../TrainGame/mainwindow.h \
        ../TrainGame/game.h \
        ../TrainGame/raillogic.h \
        ../TrainGame/railtileinterface.h \
        ../TrainGame/onesiderailtile.h \
        ../TrainGame/playerlogic.h \
        ../TrainGame/traininterface.h \
        ../TrainGame/playertrain.h \
        ../TrainGame/obstaclelogic.h \
        ../TrainGame/obstacleinterface.h \
        ../TrainGame/boulder.h \
        ../TrainGame/datareader.h \
        ../TrainGame/shop.h \
        ../TrainGame/station.h \
        ../TrainGame/background.h \
        ../TrainGame/obstaclefactory.h \
        ../TrainGame/backgroundlogic.h \
        ../TrainGame/vrtrain.h \
        ../TrainGame/vrtrainmanager.h \
        ../TrainGame/httpengine.h \
        ../TrainGame/gameexception.h \
        ../TrainGame/ioexception.h \
        ../TrainGame/leafpile.h \
        ../TrainGame/pathfinder.h \
        ../TrainGame/endgame.h \
        ../TrainGame/startwindow.h \
    testbackground.h \
    testgame.h \
    testboulder.h \
    testplayerlogic.h \
    testbackgroundlogic.h

RESOURCES += \
        ../TrainGame/res.qrc

INCLUDEPATH += \
        ../TrainGame/
