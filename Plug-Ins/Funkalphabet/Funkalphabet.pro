#-------------------------------------------------
#
# Project created by QtCreator 2014-05-24T21:38:31
#
#-------------------------------------------------

include(../../Vorgaben.pri)

CONFIG += plugin
VERSION = 0.1.0


LIBS += -lFunkalphabet -L../../../Funkalphabet/bin
INCLUDEPATH += ../../../Funkalphabet/Quellen \
	../../../Funkalphabet/tmp/ui \
	../../Klient/Quellen

TARGET = Funkalphabet

TEMPLATE = lib

HEADERS += Quellen/Funkalphabetplugin.h

