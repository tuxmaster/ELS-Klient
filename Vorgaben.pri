QT += core gui widgets

CONFIG += c++14 no_keywords

UI_DIR=tmp/ui
MOC_DIR=tmp/moc
OBJECTS_DIR=tmp/obj
RCC_DIR=tmp/rcc
DESTDIR=bin

if (linux-g++) {
    QMAKE_LFLAGS += -fuse-ld=gold
}
if (linux-clang) {
    QMAKE_LFLAGS += -flto
}
