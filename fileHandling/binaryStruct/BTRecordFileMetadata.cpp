/*******************************************************************************
 * File: BTRecordFileMetadata.cpp
 * Author: Brallan Aguilar
 * Description: TODO
 * Reference:
 ******************************************************************************/

#include <iostream>
#include "BTRecordFileMetadata.h"

// -----------------------------------------------------------------------------
// DEFINICIÓN DE CONSTANTES
// -----------------------------------------------------------------------------
const char BTRecordFileMetadata::STRING     = '0';
const char BTRecordFileMetadata::CHAR       = '1';
const char BTRecordFileMetadata::SHORT      = '2';
const char BTRecordFileMetadata::INT        = '3';
const char BTRecordFileMetadata::DOUBLE     = '4';
const char BTRecordFileMetadata::BOOL       = '5';
// -----------------------------------------------------------------------------

BTRecordFileMetadata::BTRecordFileMetadata()
{
    constructMetadata();
}

BTRecordFileMetadata::BTRecordFileMetadata(DLL<char> *pRecordStructPtr,
        const std::string &pFileName, const std::string &pOwner)
    : _recordStructPtr(pRecordStructPtr),
      _fileName(pFileName),
      _owner(pOwner)
{
    // vacío
}

DLL<IRecordDataType *> *BTRecordFileMetadata::getRecordStructPtr() const
{
    return _recordStructPtr;
}

std::string BTRecordFileMetadata::getFileName() const
{
    return _fileName;
}

void BTRecordFileMetadata::setFileName(std::string &pFileName)
{
    _fileName = pFileName;
}

unsigned short BTRecordFileMetadata::getFileSize() const
{
    return _fileSize;
}

void BTRecordFileMetadata::setFileSize(unsigned short &pFileSize)
{
    _fileSize = pFileSize;
}

unsigned short BTRecordFileMetadata::getBlockSize() const
{
    return _blockSize;
}

void BTRecordFileMetadata::setBlockSize(unsigned short &pSize)
{
    _blockSize = pSize;
}

std::string BTRecordFileMetadata::getOwner() const
{
    return _owner;
}


void BTRecordFileMetadata::setOwner(std::string &pOwner)
{
    _owner = pOwner;
}

DLL<unsigned short> *BTRecordFileMetadata::getFreeBlockListPtr() const
{
    return _freeBlockList;
}

void BTRecordFileMetadata::setFreeBlockList(DLL<unsigned short> *pFreeBlockList)
{
    _freeBlockList = pFreeBlockList;
}

DLL<unsigned short> *BTRecordFileMetadata::getUsedBlockListPtr() const
{
    return _usedBlockList;
}

void BTRecordFileMetadata::setUsedBlockList(DLL<unsigned short> *pBlockUsedList)
{
    _usedBlockList = pBlockUsedList;
}

unsigned short *BTRecordFileMetadata::getEOFPtr() const
{
    return _eofPtr;
}

void BTRecordFileMetadata::setEOFPtr(unsigned short *pEOFPtr)
{
    _eofPtr = pEOFPtr;
}

unsigned short *BTRecordFileMetadata::getBORPtr() const
{
    return _borPtr;
}

void BTRecordFileMetadata::setBORPtr(unsigned short *pBORPtr)
{
    _borPtr = pBORPtr;
}

void BTRecordFileMetadata::constructMetadata()
{
    // NOMBRE DE ARCHIVO
    std::cout << "Escriba el nombre del archivo: ";
    std::cin >> _fileName;

    // DUEÑO DEL ARCHIVO
    // TODO

    // CAMPOS DE REGISTRO

    char field;

    do {
        std::cout << "Escriba los campos presentes en el registro "
                  << "(0 para salir):\n"
                  << "1. String\n"
                  << "2. Char\n"
                  << "3. Short\n"
                  << "4. Int\n"
                  << "5. Double\n"
                  << "6. Bool\n"
                  << "> ";

        std::cin >> field;

        switch (field) {
        case '0': // salir
            break;
        case '1': // String
            _recordStructPtr->insertAtBack(STRING);
            break;
        case '2': // Char
            _recordStructPtr->insertAtBack(CHAR);
            break;
        case '3': // Short
            _recordStructPtr->insertAtBack(SHORT);
            break;
        case '4': // Int
            _recordStructPtr->insertAtBack(INT);
            break;
        case '5': // Double
            _recordStructPtr->insertAtBack(DOUBLE);
            break;
        case '6': // Bool
            _recordStructPtr->insertAtBack(BOOL);
            break;
        default:
            std::cout << "\nNúmero incorrecto\n\n";
            break;
        }
    } while (field != '0');
}
