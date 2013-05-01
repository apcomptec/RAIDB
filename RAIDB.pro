TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt
QT +=  core
QT += network

SOURCES += \
    main.cpp \
    example/fileManipulation/ex2.cpp \
    example/serverClient/ex1/server.cpp \
    example/serverClient/ex1/client.cpp \
    example/fileManipulation/ex1.cpp

OTHER_FILES += \
    doc/RAIDB_UML.xmi

HEADERS += \
    example/serverClient/ex1/server.h \
    example/serverClient/ex1/client.h \
    raid/IRaid.h \
    fileHandling/dataField/RegistryDataField.h

