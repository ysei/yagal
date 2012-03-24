QT -= gui
CONFIG += debug
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

TARGET = ../../bin/FltFuncBeagle

LIBS = -lopenbeagle-GA -lopenbeagle -lpacc