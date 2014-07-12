#-------------------------------------------------
#
# Project created by QtCreator 2014-07-12T19:13:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ELS-Klient

UI_DIR=tmp/ui
MOC_DIR=tmp/moc
OBJECTS_DIR=tmp/obj
RCC_DIR=tmp/rcc


TEMPLATE = app


SOURCES += Quellen/Start.cpp\
	Quellen/Hauptfenster.cpp \
    Quellen/Hilfsfunktionen.cpp

HEADERS  += Quellen/Hauptfenster.h \
    Quellen/Vorgaben.h \
    Quellen/Hilfsfunktionen.h

FORMS    += Formulare/Hauptfenster.ui
