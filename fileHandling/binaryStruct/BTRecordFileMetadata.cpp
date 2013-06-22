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
    this->_recordSize = 24 + ( 8 * computeRecordSize() );   // tamaño en bits de todo el registro
    this->_fr = 0;      // posición inicial del registro
    this->_eof = _fr;   // posición final del registro
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
