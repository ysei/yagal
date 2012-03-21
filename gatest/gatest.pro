TEMPLATE = app
TARGET = ../bin/gatest
CONFIG -= app_bundle
QT -= gui
LIBS += -lgtest
SOURCES += main.cpp

INCLUDEPATH = ..

HEADERS += range_test.h \
    domain_test.h \
    space_test.h \
    common.h \
    solver_test.h

LIBS += -L ../lib -lyagal -lRandomLib
