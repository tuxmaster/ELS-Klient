#-------------------------------------------------
#
# Project created by QtCreator 2014-05-24T21:38:31
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


VERSION = 0.0.2

TARGET = Funkalphabet
UI_DIR=tmp/ui
MOC_DIR=tmp/moc
OBJECTS_DIR=tmp/obj
RCC_DIR=tmp/rcc

TEMPLATE = lib


SOURCES += Quellen/Datenmodell.cpp \
    Quellen/Uebersetzen.cpp \
    Quellen/Funkalphabet.cpp

HEADERS  += Quellen/Vorgaben.h \
    Quellen/Datenmodell.h \
    Quellen/Uebersetzen.h \
    Quellen/Funkalphabet.h

FORMS    +=  Dialoge/Funkalphabet.ui

Datenbank.commands = ./DB_erstellen.sh
Datenbank.depends = $(TARGET)

QMAKE_EXTRA_TARGETS += Datenbank

RESOURCES += Bilder/Bilder.qrc
