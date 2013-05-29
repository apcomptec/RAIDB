#include <fstream>
#include <iostream>
#include <string>
#include "fileHandling/binaryStruct/BTRecordFile.h"
#include "fileHandling/binaryStruct/BTRecordFileMetadata.h"
#include "fileHandling/RecordDataType.h"
#include "util/Converter.h"
#include "raid/Disk.h"
#include "util/parser/XMLParser.h"
#include "dataStructure/n_aryrecordfile.h"
#include <bitset>

using namespace std;

int main()
{
//    XMLParser *p = new XMLParser();
//    p->createFile();

//    N_aryRecordFile* nTree = new N_aryRecordFile();
//    nTree->insertDirPtr("home");
//    nTree->insertDirPtr("tmp");
//    nTree->insertDirPtr("bin");
//    nTree->insertDirPtr("jose", "/home/");
//    nTree->insertDirPtr("daniel", "/home/");
//    nTree->insertDirPtr("badilla", "/home/");
//    nTree->insertDirPtr("dir", "/home/jose/");
//    nTree->insertDirPtr("nueva", "/home/daniel/");

//    std::cout << "\nImpresion del arbol" << std::endl;
//    nTree->printTree();

//    nTree->deleteDirPtr("/home/daniel/nueva/");
//    std::cout << "\nImpresion del arbol" << std::endl;
//    nTree->printTree();
//    std::cout << "Fin de la ejecución" << std::endl;

    // *****************************************************************************
    // LECTURA DEL ARBOL DE CARPETA Y ARCHIVO N-ARIO
    // *****************************************************************************

    // *****************************************************************************
    // PRUEBA PARA ESCRIBIR REGISTRO EN DISCO
    // *****************************************************************************
    //    std::string name = "file1";
    //    std::string data = "H";
    //    unsigned short size = 3;
    //    IRecordDataType *record1 = new RecordDataType<std::string>(name, data, size);
    //    BTRecordFileMetadata *p = new BTRecordFileMetadata();
    ////------------------------------------
    //    std::string name2 = "file2";
    //    std::string data2 = "R";
    //    unsigned short size2 = 3;
    //    IRecordDataType *record2 = new RecordDataType<std::string>(name2, data2, size2);
    ////------------------------------------
    //    std::string name3 = "file3";
    //    std::string data3 = "D";
    //    unsigned short size3 = 3;
    //    IRecordDataType *record3 = new RecordDataType<std::string>(name3, data3, size3);
    //// ------------------------------------
    //    std::string name4 = "file4";
    //    std::string data4 = "A";
    //    unsigned short size4 = 3;
    //    IRecordDataType *record4 = new RecordDataType<std::string>(name4, data4, size4);

    //    std::string name5 = "file5";
    //    std::string data5 = "B";
    //    unsigned short size5 = 3;
    //    IRecordDataType *record5 = new RecordDataType<std::string>(name5, data5, size5);

    //    std::string name6 = "file6";
    //    std::string data6 = "C";
    //    unsigned short size6 = 3;
    //    IRecordDataType *record6 = new RecordDataType<std::string>(name6, data6, size6);

    //    std::string name7 = "file7";
    //    std::string data7 = "E";
    //    unsigned short size7 = 3;
    //    IRecordDataType *record7 = new RecordDataType<std::string>(name7, data7, size7);

    //    std::string name8 = "file8";
    //    std::string data8 = "F";
    //    unsigned short size8 = 3;
    //    IRecordDataType *record8 = new RecordDataType<std::string>(name8, data8, size8);

    //    std::string name9 = "file3";
    //    std::string data9 = "G";
    //    unsigned short size9 = 3;
    //    IRecordDataType *record9 = new RecordDataType<std::string>(name9, data9, size9);

    //    std::string name10 = "file3";
    //    std::string data10 = "Z";
    //    unsigned short size10 = 3;
    //    IRecordDataType *record10 = new RecordDataType<std::string>(name10, data10, size10);


    //    DLL<IRecordDataType * > *list1 = new DLL<IRecordDataType *>(), *list2 = new DLL<IRecordDataType *>(),
    //            *list3 = new DLL<IRecordDataType *>(), *list4 = new DLL<IRecordDataType *>()
    //            , *list5 = new DLL<IRecordDataType *>(), *list6 = new DLL<IRecordDataType *>()
    //            , *list7 = new DLL<IRecordDataType *>(), *list8 = new DLL<IRecordDataType *>()
    //            , *list9 = new DLL<IRecordDataType *>(), *list10 = new DLL<IRecordDataType *>();
    //    list1->insertAtFront(record1);
    //    list2->insertAtFront(record2);
    //    list3->insertAtFront(record3);
    //    list4->insertAtFront(record4);
    //    list5->insertAtFront(record5);
    //    list6->insertAtFront(record6);
    //    list7->insertAtFront(record7);
    //    list8->insertAtFront(record8);
    //    list9->insertAtFront(record9);
    //    list10->insertAtFront(record10);
    //    //------------------------------------

    //    BTRecordFile *file = new BTRecordFile(p);
    //    file->insertRecord2Disk(list1); // inserta datos en disco
    //    file->insertRecord2Disk(list2);
    //    file->insertRecord2Disk(list3);
    //    file->insertRecord2Disk(list4);
    //    file->insertRecord2Disk(list5);
    //    file->insertRecord2Disk(list6);
    //    file->insertRecord2Disk(list7);
    //    file->insertRecord2Disk(list8);
    //    file->insertRecord2Disk(list9);
    //    file->readALLRecordsFromDisk();     // imprime los datos que están en disco
    //// PRUEBAS DE BORRADO DE DATOS EN EL DISCO
    //    file->deleteRecordFromDisk(3);  // borra datos en disco
    //    file->readALLRecordsFromDisk();
    //    file->deleteRecordFromDisk(5);
    //    file->readALLRecordsFromDisk();
    //    file->deleteRecordFromDisk(6);
    //    file->readALLRecordsFromDisk();
    //    file->deleteRecordFromDisk(2);
    //    file->readALLRecordsFromDisk();

    //    file->insertRecord2Disk(list3);
    //    file->readALLRecordsFromDisk();
    //    file->insertRecord2Disk(list10);
    //    file->readALLRecordsFromDisk();

    //    file->readOneRecordFromDisk(3);



    //------------------------------------
    //    Disk *disk = new Disk(1, 7);
    //    const char *test1 = file->getRegistryArray()[1].castRecordToBinary().c_str();
    //    const char *test2 = file->getRegistryArray()[2].castRecordToBinary().c_str();
    //    disk->write(0, test1);  // Escritura de registro
    //    disk->write(0, test2);
    //    file->readRecordFromDiskTest(*disk, 1); // Lectura de registro

    // *****************************************************************************
    // PRUEBA PARA INSERTAR y BORRAR REGISTROS
    // *****************************************************************************

    //    BTRecordFile *_fileTest = new BTRecordFile();

    //    cout << "Inserción de 10 registros sin mostrar el dato que almacena" << endl;
    //    BTRecordFile *registro = new BTRecordFile(nullptr);
    //    BTRecord *record = new BTRecord();
    //    DLL<IRecordDataType *> *listaUsuario = new DLL<IRecordDataType *>();
    //    registro->insertRecord(listaUsuario);
    //    registro->insertRecord(listaUsuario);
    //    registro->printArrayRecord();
    //    registro->deleteRecord(3);// se borra el registro 3
    //    registro->printArrayRecord();
    //    registro->deleteRecord(5);// se borra el registro 5
    //    registro->printArrayRecord();
    //    registro->deleteRecord(8);// se borra el registro 8
    //    registro->printArrayRecord();
    //    registro->deleteRecord(10);// se borra el registro 10
    //    registro->printArrayRecord();
    //    delete listaUsuario;
    //    delete registro;

    // *****************************************************************************
    // PRUEBA PARA HACER CONVERSIONES DE DATOS DE BINARIO A NORMAL Y VICEVERSA
    // *****************************************************************************
    //    Converter *c = new Converter();
    //    cout << "--------------------" << endl;
    //    cout << c->fromString2Short("3") << endl;
    //    cout << "--------------------" << endl;
    //    c->binaryToDecimal("00111");
    //    cout << "--------------------" << endl;
    //    c->decimalToBinary("7");
    //    cout << "--------------------" << endl;
    //    c->binaryToString("01001000");
    //    cout << "--------------------" << endl;
    //    c->stringToBinary("Daniel");
    //    cout << "--------------------" << endl;

    //    c->verificaValidezDouble("18.5"); // prueba si es double
    //    c->verificaValidezDouble("A");    // prueba si es double
    //    c->verificaValidezDouble("185");  // prueba si es double

    //    c->fromString2Double("0.6");
    //    c->fromDouble2String(456.7);

    std::bitset<64> Bitset64(std::string("0000010100100100111001100010000100000010100001010011100110011111"));

       double value = Bitset64.to_ulong();
       std::cout << value;
}
