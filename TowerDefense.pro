#-------------------------------------------------
#
# Project created by QtCreator 2013-08-22T22:46:33
#
#-------------------------------------------------

QT       += core gui multimedia

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TowerDefense
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    towerposition.cpp \
    tower.cpp \
    waypoint.cpp \
    enemy.cpp \
    bullet.cpp \
    audioplayer.cpp \
    plistreader.cpp \
    redtower.cpp \
    purpletower.cpp \
    bluetower.cpp \
    armorenemy.cpp \
    speedenemy.cpp \
    cloakenemy.cpp \
    arrow.cpp \
    bumb.cpp

HEADERS  += mainwindow.h \
    towerposition.h \
    tower.h \
    waypoint.h \
    utility.h \
    enemy.h \
    bullet.h \
    audioplayer.h \
    plistreader.h \
    redtower.h \
    purpletower.h \
    bluetower.h \
    cloakenemy.h \
    speedenemy.h \
    armorenemy.h \
    arrow.h \
    bomb.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
