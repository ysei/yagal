QT -= gui
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH = ..

SOURCES += main.cpp \
    domain.cpp \
    space.cpp \
    solver.cpp \
    random.cpp
TARGET = ../bin/ga

HEADERS += \
    domain.h \
    space.h \
    solver.h \
    yagal.h \
    solution.h \
    range.h \
    random.h

CXXFLAGS += -Wunused-parameter
