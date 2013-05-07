/*******************************************************************************
 * File: BTRecordFile.cpp
 * Author: Brallan Aguilar
 * Description: TODO
 * Reference:
 ******************************************************************************/

#include "BTRecordFile.h"

BTRecordFile::BTRecordFile(BTRecordFileMetadata *pMetadata)
    : _metadataPtr(pMetadata)
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

DLL<IRecord *> *BTRecordFile::getRecordListPtr() const
{
    return _recordListPtr;
}

void BTRecordFile::setRecordListPtr(DLL<IRecord *> *pListPtr)
{
    _recordListPtr = pListPtr;
}


void BTRecordFile::insertRecordPtr(DLL<IRecord *> *pListPtr)
{

}

BTRecord *BTRecordFile::deleteRecordPtr(IRecord *pRecordPtr) // TODO
{

}

BTRecord *BTRecordFile::searchRecordPtr(IRecord *pRecordPtr) const // TODO
{
}

unsigned short BTRecordFile::showFragmentation() const
{
    return 0; // TODO
}

bool BTRecordFile::defragFile()
{
    return false; // TODO
}
