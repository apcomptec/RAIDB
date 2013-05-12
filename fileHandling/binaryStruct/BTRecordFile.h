/*******************************************************************************
 * File: BTRecordFile.h
 * Author: Brallan Aguilar
 * Description: TODO
 * Reference:
 ******************************************************************************/

#ifndef BTRECORDFILE_H
#define BTRECORDFILE_H

#include <vector>
#include "fileHandling/binaryStruct/BTRecordFileMetadata.h"
#include "fileHandling/binaryStruct/BTRecord.h"
#include "fileHandling/IRecordFile.h"
#include <iostream>
#include <iomanip>

using namespace std;

class BTRecordFile: public IRecordFile{

public:

    /**
     * @brief BTRecordFile Constructor
     */
    BTRecordFile(BTRecordFileMetadata *pMetadata);

// -----------------------------------------------------------------------------
// MÉTODOS DE LA INTERFAZ IRECORDFILE
// -----------------------------------------------------------------------------
    virtual BTRecordFileMetadata *getMetadata() const;
//    virtual void setMetadata(BTRecordFileMetadata *pMetadataPtr);
    virtual DLL<IRecord *> *getRecordList() const;
    virtual void setRecordList(DLL<IRecord *> *pListPtr);
    virtual void insertRecord(DLL<IRecordDataType *> *pListPtr);
//    virtual BTRecord *deleteRecord(BTRecord *pRecordPtr);
//    virtual BTRecord *searchRecord(BTRecord *pRecordPtr) const;
    virtual BTRecord *printArrayRecord() const;
    virtual unsigned short showFragmentation() const;
    virtual bool defragFile();
// -----------------------------------------------------------------------------

    int getCounter() const;
    void setCounter(int counter);

private:
    /**
     * @brief _metadataPtr
     */
    BTRecordFileMetadata *_metadataPtr;

    /**
     * @brief _recordList
     */
    std::vector<IRecord *> *_recordList;
    DLL<IRecord *> _recordListPtr;

    int _counter;       //llevará la cantidad de registros insertados
    BTRecord *_registryArray;


};

#endif // BTRECORDFILE_H
