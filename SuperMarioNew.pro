#-------------------------------------------------
#
# Project created by QtCreator 2019-12-07T15:05:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SuperMarioNew
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp \
    bullets.cpp \
    obstacle.cpp


HEADERS  += mainwindow.h \
    somedeclare.h \
    player.h \
    bullets.h \
    obstacle.h


FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
