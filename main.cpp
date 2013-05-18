#include <fstream>
#include <iostream>
#include "fileHandling/binaryStruct/BTRecordFile.h"
#include "fileHandling/binaryStruct/BTRecordFileMetadata.h"
#include "util/Converter.h"
#include "raid/Disk.h"
#include <sstream>
#include <string>

int main()
{
    Converter *c = new Converter();
//    c->string2Binary("Hello World!");
//    c->decimal2Binary("3");
//    c->binary2Decimal("10");

//    c->binary2Decimal("1001000");
//    c->binary2String("11");
    std::cout << (c->binary2String("01001000011110110101010100011110")) << "\n";
}
