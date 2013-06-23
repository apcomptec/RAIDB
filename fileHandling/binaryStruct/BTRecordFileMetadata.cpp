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

BTRecordFileMetadata::BTRecordFileMetadata(const std::string &pFileName,
        const std::string &pOwner, DLL<IRecordDataType *> *pRecordStruct)
    : _recordStructPtr(pRecordStruct),
      _fileName(pFileName),
      _owner(pOwner)
{
    this->_numberOfRecords = 1;
    this->_tamanoMetadata = 664;
    this->_recordSize = 24 + (8 * computeRecordSize());     // tamaño en bits de todo el registro
    this->_fr = _tamanoMetadata;
    this->_eof = _fr;
    this->_freeBlockList = 0;
    this->_pointerNextBlock = 0;    // dice si tiene un puntero hacia otro bloque
}

unsigned short BTRecordFileMetadata::getPointerNextBlock() const
{
    return _pointerNextBlock;
}

void BTRecordFileMetadata::setPointerNextBlock(unsigned short pointerNextBlock)
{
    _pointerNextBlock = pointerNextBlock;
}


DLL<IRecordDataType *> *BTRecordFileMetadata::getRecordStruct() const
{
    return _recordStructPtr;
}

std::string BTRecordFileMetadata::getFileName() const
{
    return _fileName;
}

void BTRecordFileMetadata::setFileName(const std::string &pFileName)
{
    _fileName = pFileName;
}

unsigned short BTRecordFileMetadata::getFileSize() const
{
    return _fileSize;
}

std::string BTRecordFileMetadata::getOwner() const
{
    return _owner;
}

void BTRecordFileMetadata::setOwner(const std::string &pOwner)
{
    _owner = pOwner;
}

unsigned short BTRecordFileMetadata::getFreeBlockList() const
{
    return _freeBlockList;
}

void BTRecordFileMetadata::setFreeBlockList(unsigned short pFreeBlockList)
{
    _freeBlockList = pFreeBlockList;
}

DLL<unsigned short> *BTRecordFileMetadata::getUsedBlockList() const
{
    return _usedBlockList;
}

void BTRecordFileMetadata::setUsedBlockList(DLL<unsigned short> *pBlockUsedList)
{
    _usedBlockList = pBlockUsedList;
}

unsigned short BTRecordFileMetadata::getEOF() const
{
    return _eof;
}

void BTRecordFileMetadata::setEOF(const unsigned short &pEOF)
{
    _eof = pEOF;
}

unsigned short BTRecordFileMetadata::getFirstRecordPos() const
{
    return _fr;
}

void BTRecordFileMetadata::setFirstRecordPos(const unsigned short &pPos)
{
    _fr = pPos;
}

void BTRecordFileMetadata::printMetadata() const
{
    std::cout << "Nombre: " << getFileName()
              << "\nDueño: " << getOwner()
              << "\nTamaño: " << getFileSize()
              << "\nPosición último elemento borrado: " << getFreeBlockList()
              << "\nInicio de datos: " << getFirstRecordPos()
              << "\nFin de archivo: " << getEOF();

    std::cout << "\n";
    printUserRecordStruct();
}

void BTRecordFileMetadata::printUserRecordStruct() const
{
    std::cout << "Estructura de datos de usuario:\n";

    DLLNode<IRecordDataType*> *current = getRecordStruct()->getHeadPtr();

    char headerName;
    bool flag = true;

    do {
        headerName =
            *dynamic_cast<RecordDataType<char>*>
            (current->getData())->getDataPtr();

        if (headerName == BTRecordFileMetadata::STRING) {
            std::cout << "string";
        } else if (headerName == BTRecordFileMetadata::CHAR) {
            std::cout << "char";
        } else if (headerName == BTRecordFileMetadata::SHORT) {
            std::cout << "short";
        } else if (headerName == BTRecordFileMetadata::INT) {
            std::cout << "int";
        } else if (headerName == BTRecordFileMetadata::DOUBLE) {
            std::cout << "double";
        } else if (headerName == BTRecordFileMetadata::BOOL) {
            std::cout << "bool";
        } else {
            flag = false;
            std::cout << "El tipo de dato no es soportado";
        }

        if (flag) {
            std::cout << ": " << current->getData()->getName() << " ["
                      << current->getData()->getSize() << "B]";
        }

        current = current->getNextPtr();
        std::cout << "\n";
    } while (current != nullptr);

    std::cout << "\n";
}

unsigned short BTRecordFileMetadata::getRecordSize() const
{
    return _recordSize;
}

void BTRecordFileMetadata::setRecordSize(const unsigned short &pSize)
{
    _recordSize = pSize;
}

unsigned short BTRecordFileMetadata::computeRecordSize()
{
    // tamaño del registro
    unsigned short size = 0;

    DLLNode<IRecordDataType *> *currentDataByUser =
        _recordStructPtr->getHeadPtr();

    while (currentDataByUser != nullptr) {
        size += currentDataByUser->getData()->getSize();
        currentDataByUser = currentDataByUser->getNextPtr();
    }

    return size;
}

unsigned short BTRecordFileMetadata::getNumberOfRecords() const
{
    return _numberOfRecords;
}

void BTRecordFileMetadata::setNumberOfRecords(const unsigned short &pNumber)
{
    this->_numberOfRecords = pNumber;
}
