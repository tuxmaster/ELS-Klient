#-------------------------------------------------
#
# Project created by QtCreator 2014-07-12T19:13:46
#
#-------------------------------------------------
include(../Vorgaben.pri)
QT       += positioning sql


TARGET = ELS-Klient


TEMPLATE = app


SOURCES += Quellen/Start.cpp\
	Quellen/Hauptfenster.cpp \
    Quellen/Hilfsfunktionen.cpp \
    Quellen/Funkkenner.cpp \
    Quellen/Erweiterungsuebersicht.cpp \
    Quellen/Pluginversion.cpp

HEADERS  += Quellen/Hauptfenster.h \
    Quellen/Vorgaben.h \
    Quellen/Hilfsfunktionen.h \
    Quellen/Funkkenner.h \
    Quellen/Formularplugin.h \
    Quellen/Pluginversion.h \
    Quellen/Erweiterungsuebersicht.h \
    Quellen/Funkplugin.h \
    Quellen/Basisplugin.h \
    Quellen/Funkpluginfabrik.h \
    Quellen/Formularpluginfabrik.h

FORMS    += Formulare/Hauptfenster.ui \
    Formulare/Funkkenner.ui \
    Formulare/Erweiterungsuebersicht.ui

RESOURCES += \
    Bilder.qrc
