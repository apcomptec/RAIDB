/*******************************************************************************
 * File: BTRecordFile.cpp
 * Author: Brallan Aguilar
 * Description: TODO
 * Reference:
 ******************************************************************************/

#include "BTRecordFile.h"

BTRecordFile::BTRecordFile(BTRecordFileMetadata *pMetadata)
    : _index(new unsigned short(0)),
      _metadataPtr(pMetadata)

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
    BTRecord *newRecord = new BTRecord();
    newRecord->setIndex(_index);

    if (_recordListPtr->isEmpty()) { // la lista esté vacía
        unsigned short *tempPtr = new unsigned short(0);
        newRecord->setParentPtr(tempPtr);
        newRecord->setLeftChildPtr(tempPtr);
        newRecord->setRightChildPtr(tempPtr);
        newRecord->setDataList(pListPtr);
        _recordListPtr->insertAtBack(newRecord);
    } else {
        BTRecord *tempPtr = (BTRecord*) _recordListPtr->getTailPtr()->getData();
        if (*tempPtr->getLeftChildPtr() == 0) {
            newRecord->setParentPtr(tempPtr->getParentPtr());
            tempPtr->setLeftChildPtr(newRecord->getIndex());
            newRecord->setLeftChildPtr(new unsigned short(0));
            newRecord->setRightChildPtr(new unsigned short(0));
        } else if (*tempPtr->getRightChildPtr() == 0) {
            newRecord->setParentPtr(tempPtr->getParentPtr());
            tempPtr->setRightChildPtr(newRecord->getIndex());
            newRecord->setRightChildPtr(new unsigned short(0));
        } else {

        }
    }

    *_index++;
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
