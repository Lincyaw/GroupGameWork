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
    anemy.cpp \
        mainwindow.cpp \
    player.cpp \
    obstacle.cpp \
    javacup.cpp \
    mypushbutton.cpp


HEADERS  += mainwindow.h \
    anemy.h \
    somedeclare.h \
    player.h \
    obstacle.h \
    javacup.h \
    mypushbutton.h


FORMS    += mainwindow.ui

RESOURCES += \
    monster/monster.qrc \
    res.qrc
