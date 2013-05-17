#include <fstream>
#include <iostream>
#include <math.h>
#include "Disk.h"

const char Disk::POTENCY = 20;  // se define el tamaño del disco en MB

Disk::Disk(const unsigned short &pId, const unsigned short &pSize,
           unsigned short pBlockSize = 512)
    : ID(pId), SIZE(pSize), BLOCK_SIZE(pBlockSize),
      _name(std::string("disk") + std::to_string(ID))
{
    create();
    fillBlockList();
}

void Disk::write(const unsigned short &pLine, const char *pBuffer)
{
    std::ofstream outfile;
    outfile.open(_name, std::fstream::binary | std::fstream::in);
    outfile.seekp(pLine);
    outfile.write(pBuffer, sizeOfChar(pBuffer));
    outfile.close();
}

char Disk::read(const unsigned &pLine, const unsigned short &pLineLength)
{
    std::ifstream ifs(_name, std::fstream::binary | std::fstream::in);

    ifs.seekg(pLine, std::ios::beg);

    char buffer[pLineLength + 1];
    ifs.read(buffer, pLineLength + 1);

    buffer[pLineLength + 1] = '\0';

    std::cout << buffer << std::endl;

    ifs.close();
    return *buffer;
}

void Disk::create()
{
    std::ofstream ofs(_name, std::ios::binary | std::ios::out);
    ofs.seekp(((SIZE << POTENCY) - 1));
    ofs.write("", 1);
    ofs.close();
}

unsigned short Disk::sizeOfChar(const char *pChar)
{
    std::string string = pChar;
    return string.length();
}

void Disk::fillBlockList()
{

}

unsigned short Disk::computeNumberOfBlocks()
{
    return SIZE * pow(2, 20) / BLOCK_SIZE;
}
