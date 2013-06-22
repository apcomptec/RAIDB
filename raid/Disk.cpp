#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
#include "Disk.h"

const char Disk::POTENCY = 20;  // se define el tamaño del disco en MB

Disk::Disk(const unsigned short &pId, const unsigned short &pSize,
           unsigned short pBlockSize)
    : ID(pId), SIZE(pSize), BLOCK_SIZE(pBlockSize),
      NAME(std::string("disk") + std::to_string(ID))
{
    this->_securityKey = new Encryption();
    createDisk();
    fillBlockList();
}

/**
 * @brief Disk::generateSecurityKey
 * @return genera una security key
 */
std::string Disk::generateSecurityKey() const
{
    std::string p = _securityKey->generateRandomPassword(); //genera clave random
    return  _securityKey->passwordEncryption( p );    // encripta la clave
}

unsigned int Disk::createFile()
{
    return _freeBlockList.removeFromFront()->getData();
}

void Disk::write(const unsigned short &pPos, const char *pBuffer,
                 unsigned short pBlock)
{
    std::ofstream outfile;
    outfile.open(NAME, std::fstream::binary | std::fstream::in);
    if (outfile) {
        outfile.seekp(pPos * pBlock);
        outfile.write(pBuffer, sizeOfChar(pBuffer));
        outfile.close();
    } else {
        std::cout << "Hubo un error al abrir el disco " << NAME << "\n";
    }
}

char *Disk::read(const unsigned &pPos, const unsigned short &pBufferLength,
                 unsigned short pBlock)
{
    std::ifstream ifs(NAME, std::ifstream::binary);
    char *buffer;

    if (ifs) {
        buffer = new char[pBufferLength + 1];
        buffer[pBufferLength + 1] = '\0';
        ifs.seekg(pPos * pBlock, ifs.beg);
        ifs.read(buffer, pBufferLength + 1);
        if (!ifs) {
            std::cout << "ERROR: solo " << ifs.gcount()
                      << " caracteres fueron leídos";
        }

        ifs.close();
    } else {
        std::cout << "Hubo un error al abrir el disco " << NAME << "\n";
        buffer = nullptr;
    }

    return buffer;
}

unsigned short Disk::getID()
{
    return ID;
}

unsigned short Disk::getBlockSize()
{
    return BLOCK_SIZE;
}

std::string Disk::getName()
{
    return NAME;
}

void Disk::createDisk()
{
    std::ofstream ofs(NAME, std::ios::binary | std::ios::out);
    if (ofs) {
        ofs.seekp(((SIZE << POTENCY) - 1));
        ofs.write("", 1);
        ofs.close();
    } else {
        std::cout << "Hubo un error al crear el disco " << NAME << "\n";
    }
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
