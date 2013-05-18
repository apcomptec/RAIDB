#include <fstream>
#include <iostream>
#include "fileHandling/binaryStruct/BTRecordFile.h"
#include "fileHandling/binaryStruct/BTRecordFileMetadata.h"
#include "util/Converter.h"
#include "raid/Disk.h"

int main()
{
    Converter *c = new Converter();
    cout << c->stringToBinary("Hello World!");

    std::cout << (c->binaryToString("0100010001100001011011100110"
                                    "10010110010101101100")) << "\n";
}
