#-------------------------------------------------
#
# Project created by QtCreator 2014-07-12T19:13:46
#
#-------------------------------------------------

QT       += core gui widgets positioning sql

TARGET = ELS-Klient

UI_DIR=tmp/ui
MOC_DIR=tmp/moc
OBJECTS_DIR=tmp/obj
RCC_DIR=tmp/rcc

TEMPLATE = app

INCLUDEPATH += ../Funkalphabet/Quellen \
		../Funkalphabet/tmp/ui
LIBS += -L ../Funkalphabet/ -lFunkalphabet

SOURCES += Quellen/Start.cpp\
	Quellen/Hauptfenster.cpp \
    Quellen/Hilfsfunktionen.cpp \
    Quellen/Funkkenner.cpp

HEADERS  += Quellen/Hauptfenster.h \
    Quellen/Vorgaben.h \
    Quellen/Hilfsfunktionen.h \
    Quellen/Funkkenner.h \
    Quellen/Formularplugin.h \
    Quellen/Pluginversion.h

FORMS    += Formulare/Hauptfenster.ui \
    Formulare/Funkkenner.ui
