QT += core
QT -= gui

CONFIG += c++11

TARGET = MIA_Proyecto1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    parser.cpp \
    scanner.cpp \
    mkdisk.cpp \
    rmdisk.cpp \
    fdisk.cpp \
    mount.cpp \
    unmount.cpp \
    estructuras.cpp \
    mkfs.cpp \
    user.cpp \
    mkgrp.cpp \
    rmgrp.cpp \
    mkusr.cpp \
    rmusr.cpp \
    mkfile.cpp \
    rep.cpp \
    file.cpp \
    carpeta.cpp \
    mkdir.cpp \
    loss.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DISTFILES += \
    lexico.l \
    parser.y \
    .gitignore

HEADERS += \
    parser.h \
    scanner.h \
    mkdisk.h \
    rmdisk.h \
    fdisk.h \
    mount.h \
    unmount.h \
    estructuras.h \
    mkfs.h \
    user.h \
    mkgrp.h \
    rmgrp.h \
    mkusr.h \
    rmusr.h \
    mkfile.h \
    rep.h \
    file.h \
    carpeta.h \
    mkdir.h \
    loss.h
