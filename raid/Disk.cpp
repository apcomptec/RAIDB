#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
#include "Disk.h"

char *a = new char('2');

const char Disk::POTENCY = 20;  // se define el tamaño del disco en MB

Disk::Disk(const unsigned short &pId, const unsigned short &pSize,
           unsigned short pBlockSize)
    : ID(pId), SIZE(pSize), BLOCK_SIZE(pBlockSize),
      _name(std::string("disk") + std::to_string(ID))
{
    createDisk();
    fillBlockList();
}

unsigned int Disk::createFile()
{
    return _freeBlockList.removeFromFront()->getData();
}

void Disk::write(const unsigned short &pPos, const char *pBuffer)
{
    std::ofstream outfile;
    outfile.open(_name, std::fstream::binary | std::fstream::in);
    outfile.seekp(pPos);
    outfile.write(pBuffer, sizeOfChar(pBuffer));
    outfile.close();
}

char *Disk::read(const unsigned &pPos, const unsigned short &pBufferLength)
{
    std::ifstream ifs(_name, std::ifstream::binary);

    char *buffer = new char[pBufferLength + 1];
    ifs.seekg(pPos, ifs.beg);
    ifs.read(buffer, pBufferLength + 1);

    buffer[pBufferLength + 1] = '\0';

    ifs.close();

    return buffer;
}

void Disk::createDisk()
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
    for (unsigned int var = computeNumberOfBlocks(); var > 0; --var) {
        _freeBlockList.insertAtFront(var);
    }
}

unsigned int Disk::computeNumberOfBlocks()
{
    return SIZE * pow(2, POTENCY) / BLOCK_SIZE;
}

