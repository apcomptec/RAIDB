#include <fstream>
#include <iostream>
#include "fileHandling/binaryStruct/BTRecordFile.h"
#include "fileHandling/binaryStruct/BTRecordFileMetadata.h"
#include "fileHandling/RecordDataType.h"
#include "util/Converter.h"
#include "raid/Disk.h"
#include <string>

using namespace std;

void sum(char pChar);

int main()
{
//    Converter *c = new Converter();
//nsodnanfapsofasnfos
//    cout << "--------------------" << endl;
//    c->binaryToDecimal("00111");
//    cout << "--------------------" << endl;
//    c->decimalToBinary("7");
//    cout << "--------------------" << endl;
//    c->binaryToString("01001000");
//    cout << "--------------------" << endl;
//    c->stringToBinary("Daniel");
//    cout << "--------------------" << endl;

    std::string name = "JUJU";
    std::string data = "H";
    unsigned short size = 3;
    IRecordDataType * record1 = new RecordDataType<std::string>(name, data, size);

    BTRecordFileMetadata *p = new BTRecordFileMetadata();


    std::string name2 = "fueeeee";
    std::string data2 = "576";
    unsigned short size2 = 8;
    IRecordDataType * record2 = new RecordDataType<std::string>(name2, data2, size2);

    DLL<IRecordDataType * > *list1 = new DLL<IRecordDataType *>(), *list2 = new DLL<IRecordDataType *>();

    list1->insertAtFront(record1);
    list2->insertAtFront(record2);

//    std::string name3 = "fdsjnfs";
//    std::string data3 = "9834";
//    unsigned short size3 = 8576;
//    IRecordDataType * record3 = new RecordDataType<std::string>(name3, data3, size3);

    BTRecordFile *file = new BTRecordFile(p);

    file->insertRecord(list1);
    //file->insertRecord(list2);
    //  file->insertRecord(list2);

    file->printArrayRecord();

    Disk *disk = new Disk(1, 7);

   // const char *test = file->getRegistryArray()[1].castRecordToBinary().c_str();

//    const char *buffer = "12878789908";
//    disk->write(0, buffer);
//    cout << "\n\nLecura: " << disk->read(0, 4);
    //std::cout << "%%%%%%%% " << file->insertRecord(list1)->castRecordToBinary().c_str() << "\n";
    disk->write(0,file->insertRecord(list1)->castRecordToBinary().c_str());
   // disk->write(0,file->insertRecord(list2)->castRecordToBinary().c_str());
    file->readRecordFromDiskTest(*disk, 1);

    //    list->insertAtFront(record325);
//    record->setDataList(list1);

//    record->printRecord();
//    record->castRecordToBinary();
//    DLL<std::string * > *dll = new DLL<std::string* >();

//    std::string b = "jujuj";
//    std::string *r = &b;
//    dll->insertAtBack(r);

// *****************************************************************************
// PRUEBA PARA INSERTAR REGISTROS
// *****************************************************************************

//    BTRecordFile *_fileTest = new BTRecordFile();

//    cout << "Inserción de 10 registros sin mostrar el dato que almacena" << endl;
//    BTRecordFile *registro = new BTRecordFile(nullptr);
//     BTRecord *record = new BTRecord();
//        DLL<IRecordDataType *> *listaUsuario = new DLL<IRecordDataType *>();
//        registro->insertRecord(listaUsuario);
//        registro->insertRecord(listaUsuario);
//        registro->printArrayRecord();

////       registro->deleteRecord(3);// se borra el registro 3
////       registro->printArrayRecord();
////       registro->deleteRecord(5);// se borra el registro 5
////       registro->printArrayRecord();
////       registro->deleteRecord(8);// se borra el registro 8
////       registro->printArrayRecord();
////       registro->deleteRecord(10);// se borra el registro 10
////       registro->printArrayRecord();
//        delete listaUsuario;

//       delete registro;



}
