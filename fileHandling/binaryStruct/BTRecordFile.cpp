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

BTRecordFileMetadata *BTRecordFile::getMetadata() const
{
    return _metadataPtr;
}

void BTRecordFile::setMetadata(BTRecordFileMetadata *pMetadataPtr)
{
    _metadataPtr = pMetadataPtr;
}

DLL<IRecord *> *BTRecordFile::getRecordList() const
{
    return _recordListPtr;
}

void BTRecordFile::setRecordList(DLL<IRecord *> *pListPtr)
{
    _recordListPtr = pListPtr;
}


void BTRecordFile::insertRecord(DLL<IRecordDataType *> *pListPtr)
{

}

BTRecord *BTRecordFile::deleteRecord(BTRecord *pRecordPtr) // TODO
{

}

BTRecord *BTRecordFile::searchRecord(BTRecord *pRecordPtr) const // TODO
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
