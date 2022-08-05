#-------------------------------------------------
#
# Project created by QtCreator 2022-07-26T14:13:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    custom.cpp \
    mysquarea.cpp \
    customview.cpp

HEADERS  += mainwindow.h \
    custom.h \
    mygraphicsview.h \
    mysquarea.h \
    bfs.h \
    customview.h

FORMS    += mainwindow.ui
