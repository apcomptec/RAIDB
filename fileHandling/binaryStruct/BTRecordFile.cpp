///*******************************************************************************
// * File: BTRecordFile.cpp
// * Author: Brallan Aguilar
// * Description: TODO
// * Reference:
// ******************************************************************************/

//#include "BTRecordFile.h"

//BTRecordFile::BTRecordFile(std::string &pFileName, std::string &pOwner)

//{
//    getMetadataPtr()->setFileName(pFileName);
//    getMetadataPtr()->setOwner(pOwner);
//    getMetadataPtr()->getBORPtr() = _recordList.getHeadPtr();
//    getMetadataPtr()->getEOFPtr() = _recordList.getTailPtr();
//}

//BTRecordFileMetadata *BTRecordFile::getMetadataPtr() const
//{
//    return _metadataPtr;
//}

//void BTRecordFile::setMetadata(BTRecordFileMetadata *pMetadataPtr)
//{
//    _metadataPtr = pMetadataPtr;
//}

//DLL<IRecord *> *BTRecordFile::getRecordListPtr()
//{
//    return &_recordList;
//}

//void BTRecordFile::setRecordListPtr(DLL<IRecord *> *pListPtr)
//{
//    _recordList = *pListPtr;
//}


//void BTRecordFile::insertRecordPtr(DLL<IRecord *> *pListPtr)
//{
//    BTRecord *record = new BTRecord();
//    record->setDataList(pListPtr);
//    _recordList.insertAtBack(record);

//    if (_recordList.isEmpty()) { // no se han insertado registros
//        record->setParentPtr(nullptr);
//        record->setLeftChildPtr(nullptr);
//        record->setRightChildPtr(nullptr);
//    } else {
//        record->setParentPtr(getMetadataPtr()->getEOFPtr());
//        DLLNode *parentTmp = getMetadataPtr()->getEOFPtr();

//    }
//}

//BTRecord *BTRecordFile::deleteRecordPtr(BTRecord *pRecordPtr) // TODO
//{
//    BTRecord *tmp = pRecordPtr;
//    return tmp;
//}

//BTRecord *BTRecordFile::searchRecordPtr(BTRecord *pRecordPtr) const // TODO
//{
//    BTRecord *tmp = pRecordPtr;
//    return tmp;
//}

//unsigned short BTRecordFile::showFragmentation() const
//{
//    return 0; // TODO
//}

//bool BTRecordFile::defragFile()
//{
//    return false; // TODO
//}
