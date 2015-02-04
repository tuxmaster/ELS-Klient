QT      += core gui widgets designer

CONFIG	+= plugin

TEMPLATE =lib
TARGET=FunkalphabetDesigner

UI_DIR=tmp/ui
MOC_DIR=tmp/moc
OBJECTS_DIR=tmp/obj
RCC_DIR=tmp/rcc

LIBS += -lFunkalphabet -L./

FORMS    += Dialoge/Funkalphabet.ui

HEADERS +=  Quellen/FunkalphabetPlugin.h

SOURCES += Quellen/FunkalphabetPlugin.cpp

OTHER_FILES +=FunkalphabetDesigner.json
