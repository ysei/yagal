QT -= gui
CONFIG += console static
CONFIG -= app_bundle

TEMPLATE = lib

INCLUDEPATH = ..

SOURCES += domain.cpp \
    space.cpp \
    solver.cpp \
    random.cpp

TARGET = ../lib/yagal

HEADERS += \
    domain.h \
    space.h \
    solver.h \
    yagal.h \
    solution.h \
    range.h \
    random.h \
    types.h
