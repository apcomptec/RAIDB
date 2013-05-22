/*******************************************************************************
 * File: BTRecordFileMetadata.cpp
 * Author: Brallan Aguilar
 * Description: TODO
 * Reference:
 ******************************************************************************/

#include <iostream>
#include "BTRecordFileMetadata.h"
#include "fileHandling/RecordDataType.h"

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
    : _recordStructPtr(new DLL<IRecordDataType*>())
{
    constructMetadata();
}

BTRecordFileMetadata::BTRecordFileMetadata(DLL<IRecordDataType *> *pRecordStructPtr,
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

    char field, data;
    unsigned short length;
    std::string name;
    RecordDataType<char> *header;
    bool flag = true;

//    _recordStructPtr = new RecordDataType(_fileName,)

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

        std::cout << "\nNombre del campo: ";
        std::cin >> name;

        std::cout << "\nDefina su tamaño (en B): ";
        std::cin >> length;

        switch (field) {
        case '0': // salir
            break;
        case '1': // String
            name = "string";
            data = STRING;
            break;
        case '2': // Char
            name = "char";
            data = CHAR;
            break;
        case '3': // Short
            name = "short";
            data = SHORT;
            break;
        case '4': // Int
            name = "int";
            data = INT;
            break;
        case '5': // Double
            name = "double";
            data = DOUBLE;
            break;
        case '6': // Bool
            name = "bool";
            data = BOOL;
            break;
        default:
            std::cout << "No existe el tipo especificado\n";
            flag = false;
        }

        if (flag) {
            header = new RecordDataType<char>(name, data, length);
            _recordStructPtr->insertAtBack(header);
        }

    } while (field != '0');
}
