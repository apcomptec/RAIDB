/*******************************************************************************
 * File: BTRecordFileMetadata.cpp
 * Author: Brallan Aguilar
 * Description: TODO
 * Reference:
 ******************************************************************************/

#include "BTRecordFileMetadata.h"

BTRecordFileMetadata::BTRecordFileMetadata()
{
}

DLL<char> *BTRecordFileMetadata::getRecordStructPtr() const
{
}

std::string BTRecordFileMetadata::getFileName() const
{
}

void BTRecordFileMetadata::setFileName(std::string &pFileName)
{
}

unsigned short BTRecordFileMetadata::getFileSize() const
{
}

void BTRecordFileMetadata::setFileSize(unsigned short &pFileSize)
{
}

unsigned short BTRecordFileMetadata::getBlockSize() const
{
}

void BTRecordFileMetadata::setBlockSize(unsigned short &pSize)
{
}

std::string BTRecordFileMetadata::getOwner() const
{
}

DLL<unsigned short> *BTRecordFileMetadata::getFreeBlockListPtr() const
{
}

void BTRecordFileMetadata::setFreeBlockList(DLL<unsigned short> *pFreeBlockList)
{
}

DLL<unsigned short> *BTRecordFileMetadata::getBlockUsedListPtr() const
{
}

void BTRecordFileMetadata::setUsedBlockList(DLL<unsigned short> *pBlockUsedList)
{
}

unsigned short *BTRecordFileMetadata::getEOFPtr() const
{
}

void BTRecordFileMetadata::setEOFPtr(unsigned short *pEOFPtr)
{
}

void BTRecordFileMetadata::setOwner(std::string &pOwner)
{
}
