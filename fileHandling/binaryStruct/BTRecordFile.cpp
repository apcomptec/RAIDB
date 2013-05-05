/*******************************************************************************
 * File: BTRecordFile.cpp
 * Author: Brallan Aguilar
 * Description: TODO
 * Reference:
 ******************************************************************************/

#include "BTRecordFile.h"

BTRecordFile::BTRecordFile()
{
}

BTRecordFileMetadata *BTRecordFile::getMetadataPtr() const
{
    return _metadataPtr;
}

void BTRecordFile::setMetadata(BTRecordFileMetadata *pMetadataPtr)
{
    _metadataPtr = pMetadataPtr;
}

DLL<IRecord *> *BTRecordFile::getRecordListPtr()
{
    return &_recordList;
}

void BTRecordFile::setRecordListPtr(DLL<IRecord *> *pListPtr)
{
    _recordList = *pListPtr;
}

BTRecord *BTRecordFile::deleteRecordPtr(BTRecord *pRecordPtr) // TODO
{
    BTRecord *tmp = pRecordPtr;
    return tmp;
}

BTRecord *BTRecordFile::searchRecordPtr(BTRecord *pRecordPtr) const // TODO
{
    BTRecord *tmp = pRecordPtr;
    return tmp;
}

unsigned short BTRecordFile::showFragmentation() const
{
    return 0; // TODO
}

bool BTRecordFile::defragFile()
{
    return false; // TODO
}

void BTRecordFile::insertRecordPtr(BTRecord *pRecordPtr)
{
    pRecordPtr++; // TODO
}
