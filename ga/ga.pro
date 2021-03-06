QT -= gui
CONFIG += console debug
CONFIG -= app_bundle

TEMPLATE = lib

INCLUDEPATH = ..

SOURCES += domain.cpp \
    space.cpp \
    solver.cpp \
    random.cpp \
    operators.cpp


TARGET = ../lib/yagal

LIBS = -L../lib -lRandomLib

HEADERS += \
    domain.h \
    space.h \
    solver.h \
    yagal.h \
    range.h \
    random.h \
    types.h \
    domain.inl \
    initializer.h \
    operators.h
