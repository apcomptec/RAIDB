#include <fstream>
#include "Disk.h"

const char Disk::POTENCY = 20;

Disk::Disk(const unsigned short &pId, const unsigned short &pSize,
           unsigned short &pBlockSize)
    : ID(pId), SIZE(pSize), BLOCK_SIZE(pBlockSize),
      _name(std::string("disk") + std::to_string(ID))
{
    create();
}

void Disk::write(const unsigned short &pLine, const char *pBuffer)
{
    std::ofstream outfile;
    outfile.open(_name);
    outfile.seekp(pLine);
    outfile.write(pBuffer, sizeof(pBuffer));
    outfile.close();
}

void Disk::create()
{
    std::ofstream ofs(_name, std::ios::out);
    ofs.seekp(((SIZE << POTENCY) - 1));
    ofs.write("", 1);
    ofs.close();
}
