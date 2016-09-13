QT += core
QT -= gui

CONFIG += c++11

TARGET = app2_test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    fonctions.cpp \
    MpyFrac.c

DISTFILES += \
    fonctions_asm.asm \
    sub.asm \
    Division.asm \
    mpy.asm \
    Addition.asm \
    MpyFloatPoint.asm \
    MpyFrac.asm \
    MpyFloatPoint .asm \
    MpyFloatPoint .asm \
    MpyFloatPoint .asm \
    MpyFloatPoint.asm

HEADERS += \
    fonctions.h
