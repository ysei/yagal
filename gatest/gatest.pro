TEMPLATE = app
CONFIG -= app_bundle
QT -= gui
LIBS += -lgtest
SOURCES += main.cpp

HEADERS += range_test.h \
    domain_test.h

LIBS += -L ../lib -lyagal
