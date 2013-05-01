TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt
QT +=  core
QT += network

SOURCES += \
    example/ex1/client.cpp \
    example/ex1/main.cpp \
    example/ex1/server.cpp

OTHER_FILES += \
    doc/RAIDB_UML.xmi

HEADERS += \
    server.h \
    client.h

