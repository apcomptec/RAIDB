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
#include <QDebug>

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
//    virtual BTRecordFileMetadata *getMetadata() const;
//    virtual void setMetadata(BTRecordFileMetadata *pMetadataPtr);
    virtual DLL<IRecord *> *getRecordList() const;
    virtual void setRecordList(DLL<IRecord *> *pListPtr);
    virtual BTRecordFileMetadata *getMetadata() const;
    virtual void setMetadata(BTRecordFileMetadata *pMetadataPtr);
    virtual void insertRecord(DLL<IRecordDataType *> *pListPtr);
    void insertRecordAUX( BTRecord *pNewRecord, unsigned short pHDer );
    virtual BTRecord *deleteRecord(unsigned short pDatoBorrado);
    virtual BTRecord *searchRecord(BTRecord *pRecordPtr) const;
    virtual BTRecord *printArrayRecord() const;

    virtual unsigned short showFragmentation() const;
    virtual bool defragFile();
// -----------------------------------------------------------------------------

    int getCounter() const;
    void setCounter( int counter );
    unsigned short getListFreeBlocks() const;
    void setListFreeBlocks( unsigned short pListFreeBlocks );
    ~BTRecordFile();

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
    unsigned short _listFreeBlocks;


};

#endif // BTRECORDFILE_H
