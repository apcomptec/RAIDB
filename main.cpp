#include <fstream>
#include <iostream>
#include "fileHandling/binaryStruct/BTRecordFile.h"
#include "fileHandling/binaryStruct/BTRecordFileMetadata.h"
#include "fileHandling/RecordDataType.h"
#include "util/Converter.h"
#include "raid/Disk.h"
#include <string>

using namespace std;

int main()
{
//    Converter *c = new Converter();

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

    std::string name2 = "fueeeee";
    std::string data2 = "576";
    unsigned short size2 = 8;
    IRecordDataType * record2 = new RecordDataType<std::string>(name2, data2, size2);

    BTRecord * record = new BTRecord();

    DLL<IRecordDataType * > *list1 = new DLL<IRecordDataType *>(), *list2 = new DLL<IRecordDataType *>();

    list1->insertAtFront(record1);
    list1->insertAtFront(record2);

    std::string name3 = "fdsjnfs";
    std::string data3 = "9834";
    unsigned short size3 = 8576;
    IRecordDataType * record3 = new RecordDataType<std::string>(name3, data3, size3);

    BTRecordFile *file = new BTRecordFile(nullptr);

    file->insertRecord(list1);
    file->insertRecord(list2);

    file->printArrayRecord();

    Disk *disk = new Disk(1,7);

    const char *test = file->getRegistryArray()[1].castRecordToBinary().c_str();
    disk->write(0, test);

//    disk->write(0,file->insertRecord(list1)->castRecordToBinary());



//    list->insertAtFront(record325);
//    record->setDataList(list1);

//    record->printRecord();
//    record->castRecordToBinary();
//    DLL<std::string * > *dll = new DLL<std::string* >();

//    std::string b = "jujuj";
//    std::string *r = &b;
//    dll->insertAtBack(r);
    return 0;
}
