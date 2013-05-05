TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt
QT +=  core
QT += network
Qt += xml
QMAKE_CXXFLAGS += -std=c++0x

SOURCES += \
    main.cpp \
    example/fileManipulation/ex2.cpp \
    example/serverClient/ex1/server.cpp \
    example/serverClient/ex1/client.cpp \
    example/fileManipulation/ex1.cpp \
    fileHandling/RecordData.cpp \
    dataStructure/n_aryrecordfilenode.cpp \
    example/fileManipulation/ex3.cpp \
    example/fileManipulation/ex4.cpp \
    example/md5.cpp \
    fileHandling/binaryStruct/BTRecord.cpp \
    fileHandling/binaryStruct/BTRecordFile.cpp \
    fileHandling/binaryStruct/BTRecordFileMetadata.cpp \
    XMLParser.cpp \
    dataStructure/n_aryrecordfilenode.cpp

OTHER_FILES += \
    doc/RAIDB_UML.xmi \
    doc/RAIDB_UML.pdf

HEADERS += \
    example/serverClient/ex1/server.h \
    example/serverClient/ex1/client.h \
    raid/IRaid.h \
    dataStructure/DLLNode.h \
    dataStructure/DLL.h \
    fileHandling/IRecordDataType.h \
    fileHandling/RecordData.h \
    fileHandling/RecordDataType.h \
    fileHandling/IRecord.h \
    XMLParser.h \
    dataStructure/IN_aryNode.h \
    dataStructure/IN_aryTree.h \
    dataStructure/n_aryrecordfilenode.h \
    fileHandling/IRecordFile.h \
    fileHandling/IMetadata.h \
    fileHandling/binaryStruct/BTRecord.h \
    fileHandling/binaryStruct/BTRecordFile.h \
    fileHandling/binaryStruct/BTRecordFileMetadata.h \
    dataStructure/n_aryrecordfilenode.h
