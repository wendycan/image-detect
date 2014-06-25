#-------------------------------------------------
#
# Project created by QtCreator 2014-06-25T13:52:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = img-detection
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/opt/opencv/include

LIBS += -L/usr/local/lib \
     -lopencv_core \
     -lopencv_imgproc \
     -lopencv_features2d\
     -lopencv_highgui
