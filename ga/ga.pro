QT -= gui
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    domain.cpp \
    space.cpp \
    solver.cpp
TARGET = ../bin/ga 

HEADERS += \
    ga.h \
    domain.h \
    space.h \
    solver.h