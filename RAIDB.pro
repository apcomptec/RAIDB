TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt
QT +=  core
QT += network

SOURCES += \
    example/ex1/client.cpp \
    example/ex1/server.cpp \
    main.cpp

OTHER_FILES += \
    doc/RAIDB_UML.xmi

HEADERS += \
    example/ex1/client.h \
    example/ex1/server.h

