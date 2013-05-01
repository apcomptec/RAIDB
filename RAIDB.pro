TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt
QT +=  core
QT += network

SOURCES += main.cpp \
    server.cpp \
    client.cpp

OTHER_FILES += \
    doc/RAIDB_UML.xmi

HEADERS += \
    server.h \
    client.h

