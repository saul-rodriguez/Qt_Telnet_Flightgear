#-------------------------------------------------
#
# Project created by QtCreator 2015-01-25T10:19:24
#
#-------------------------------------------------

QT       += core gui\
            network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qt_Telnet_Flightgear
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../../Qtraspberrylib/qttelnet.cpp

LIBS += -lwiringPi

HEADERS  += mainwindow.h \
    ../../Qtraspberrylib/qttelnet.h

FORMS    += mainwindow.ui
