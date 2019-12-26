#-------------------------------------------------
#
# Project created by QtCreator 2019-12-07T15:05:53
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SuperMarioNew
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp \
    obstacle.cpp \
    hello.cpp


HEADERS  += mainwindow.h \
    somedeclare.h \
    player.h \
    obstacle.h \
    hello.h


FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
