#include <fstream>
#include <iostream>
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
    outfile.open(_name, std::fstream::binary | std::fstream::in);
    outfile.seekp(pLine);
    outfile.write(pBuffer, sizeOfChar(pBuffer));
    outfile.close();
}

char Disk::read(const unsigned &pLine, const unsigned short &pLineLength)
{
    std::ifstream ifs(_name, std::fstream::binary | std::fstream::in);

//    std::string line;
//    getline(ifs, line);
//    std::cout << line;
//    fstream myFile("test.txt", ios::in | ios::out | ios::trunc);

    // Add the characters "Hello World!" to the file
//    ifs << "Hello World!";

    // Seek to 6 characters from the beginning of the file
//    std::cout << pLine * BLOCK_SIZE;
    ifs.seekg(pLine, std::ios::beg);
//    std::cout << ifs.;
    char buffer[pLineLength + 1];
    ifs.read(buffer, pLineLength + 1);

    // End the buffer with a null terminating character
    buffer[pLineLength + 1] = '\0';

    // Output the contents read from the file and close it
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
