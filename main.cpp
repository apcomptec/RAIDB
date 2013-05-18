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
    Converter *c = new Converter();

    cout << "\n--------------------" << endl;
    c->binaryToDecimal("0111");
    cout << "\n--------------------" << endl;
    c->decimalToBinary("7");
    cout << "\n--------------------" << endl;
    c->binaryToString("01001000");
    cout << "\n--------------------" << endl;
    c->stringToBinary("Daniel");

//    std::string name = "JUJU";
//    std::string data = "97782";
//    unsigned short size = 3;
//    IRecordDataType * record324 = new RecordDataType<std::string>(name, data, size);

//    std::string name2 = "fueeeee";
//    std::string data2 = "576";
//    unsigned short size2 = 8;
//    IRecordDataType * record325 = new RecordDataType<std::string>(name2, data2, size2);

//    BTRecord * record = new BTRecord();

//    DLL<IRecordDataType * > *list = new DLL<IRecordDataType *>();
//    list->insertAtFront(record324);
//    list->insertAtFront(record325);
////    list->insertAtFront(record325);
//    record->setDataList(list);

//    record->printRecord();
//    record->castRecordToBinary();
//    DLL<std::string * > *dll = new DLL<std::string* >();

//    std::string b = "jujuj";
//    std::string *r = &b;
//    dll->insertAtBack(r);


    return 0;
}
