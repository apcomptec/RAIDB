TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt
QT +=  core
QT += network
QT += xml
QT += testlib

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += \
    example/fileManipulation/ex2.cpp \
    example/fileManipulation/ex1.cpp \
    dataStructure/n_aryrecordfilenode.cpp \
    example/fileManipulation/ex3.cpp \
    example/fileManipulation/ex4.cpp \
    example/md5.cpp \
    fileHandling/binaryStruct/BTRecord.cpp \
    fileHandling/binaryStruct/BTRecordFile.cpp \
    fileHandling/binaryStruct/BTRecordFileMetadata.cpp \
    dataStructure/n_aryrecordfilenode.cpp \
    example/fileManipulation/ex5.cpp \
    example/fileManipulation/ex6.cpp \
    example/fileManipulation/ex7.cpp \
    example/fileManipulation/ex8/ClientData.cpp \
    example/fileManipulation/ex8/ex6CreateRandomFile.cpp \
    example/fileManipulation/ex8/ex8WrittingRandomFile.cpp \
    example/fileManipulation/ex8/ex8ReadingRandomFile.cpp \
    main.cpp \
    Client-Server/threadserver.cpp \
    Client-Server/server.cpp \
    Client-Server/mainClient.cpp \
    Client-Server/client.cpp \
    Client-Server/mainServer.cpp \
    dataStructure/n_aryrecordfile.cpp\
    raid/Disk.cpp \
    util/Converter.cpp \
    raid/raid0.cpp\
    simulation/ARecordSimulable.cpp \
    simulation/recordType/BTRFLocalSimulation.cpp \
    simulation/recordType/BTRFSimulation.cpp \
    util/parser/XMLParser.cpp \
    util/parser/FileSystemParser.cpp \
    Client-Server/clientmultiple.cpp \
    util/parser/Logs.cpp \
    UnitTestCase/unittesting.cpp \
    util/Encryption.cpp

OTHER_FILES += \
    doc/RAIDB_UML.xmi \
    doc/RAIDB_UML.pdf \
    doc/fileHandling.ods \
    doc/ProtocoloV1.0.pdf \
    doc/recordExample.txt \
    doc/PruebaRegistro.xml \
    doc/PruebaWriteRegistro.xml \
    doc/PruebaReadRegistro.xml \
    doc/Ficheros.pdf \
    doc/manejoArchivos2.JPG \
    doc/manejoArchivos1.JPG \
    doc/InformacionServidor.xml \
    doc/PALMADAS.pdf \
    doc/DibujoProgra.jpg

HEADERS += \
    raid/IRaid.h \
    dataStructure/DLLNode.h \
    dataStructure/DLL.h \
    fileHandling/IRecordDataType.h \
    fileHandling/RecordDataType.h \
    fileHandling/IRecord.h \
    dataStructure/IN_aryNode.h \
    dataStructure/IN_aryTree.h \
    dataStructure/n_aryrecordfilenode.h \
    fileHandling/IRecordFile.h \
    fileHandling/IMetadata.h \
    fileHandling/binaryStruct/BTRecord.h \
    fileHandling/binaryStruct/BTRecordFile.h \
    fileHandling/binaryStruct/BTRecordFileMetadata.h \
    dataStructure/n_aryrecordfilenode.h \
    example/fileManipulation/ex8/ClientData.h \
    Client-Server/threadserver.h \
    Client-Server/server.h \
    Client-Server/client.h \
    dataStructure/n_aryrecordfile.h \
    raid/Disk.h \
    util/Converter.h \
    raid/raid0.h\
    simulation/ASimulable.h \
    simulation/ARecordSimulable.h \
    simulation/LocalSimulation.h \
    simulation/recordType/BTRFSimulation.h \
    simulation/recordType/BTRFLocalSimulation.h \
    util/parser/IParser.h \
    util/parser/XMLParser.h \
    util/parser/FileSystemParser.h \
    Client-Server/clientmultiple.h \
    util/parser/Logs.h \
    UnitTestCase/unittesting.h \
    util/Encryption.h
