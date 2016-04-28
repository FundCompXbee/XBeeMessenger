#-------------------------------------------------
#
# Project created by QtCreator 2016-04-13T14:55:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = messenger
TEMPLATE = app


SOURCES += main.cpp\
        messenger.cpp \
    ../../Pi/client.cpp \
    ../../Pi/envelope.cpp \
    ../../Pi/serial.cpp

HEADERS  += messenger.h \
    ../../Pi/client.hpp \
    ../../Pi/envelope.hpp \
    ../../Pi/serial.hpp

FORMS    += messenger.ui
