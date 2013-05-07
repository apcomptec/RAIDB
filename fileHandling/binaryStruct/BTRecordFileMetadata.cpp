/*******************************************************************************
 * File: BTRecordFileMetadata.cpp
 * Author: Brallan Aguilar
 * Description: TODO
 * Reference:
 ******************************************************************************/

#include "BTRecordFileMetadata.h"

BTRecordFileMetadata::BTRecordFileMetadata(DLL<std::string> *pRecordStructPtr,
        std::string &pFileName, std::string &pOwner)
    : _recordStructPtr(pRecordStructPtr),
      _fileName(pFileName),
      _owner(pOwner)
{
}

DLL<std::string> *BTRecordFileMetadata::getRecordStructPtr() const
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
