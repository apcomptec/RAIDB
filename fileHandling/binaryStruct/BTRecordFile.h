/*******************************************************************************
 * File: BTRecordFile.h
 * Author: Brallan Aguilar y Daniel Araya
 * Description: TODO
 * Reference:
 ******************************************************************************/

#ifndef BTRECORDFILE_H
#define BTRECORDFILE_H

#include "fileHandling/binaryStruct/BTRecordFileMetadata.h"
#include "fileHandling/binaryStruct/BTRecord.h"
#include "fileHandling/IRecordFile.h"
#include <iostream>
#include <iomanip>
#include <QDebug>
#include "raid/Disk.h"
#include "util/Converter.h"

using namespace std;

class BTRecordFile: public IRecordFile
{

public:

    /**
     * @brief BTRecordFile Constructor
     */
    BTRecordFile(BTRecordFileMetadata *pMetadata);

// -----------------------------------------------------------------------------
// MÉTODOS DE LA INTERFAZ IRECORDFILE
// -----------------------------------------------------------------------------
    virtual BTRecordFileMetadata *getMetadata() const;
    virtual void setMetadata(IMetadata *pMetadataPtr);
    virtual DLL<IRecord *> *getRecordList() const;
    virtual void setRecordList(DLL<IRecord *> *pListPtr);
    virtual BTRecord *insertRecord(DLL<IRecordDataType *> *pListPtr);
//    virtual BTRecord *deleteRecord(IMetadata *pRecordPtr);
    virtual BTRecord *deleteRecord(unsigned short pDatoBorrado);
//    virtual BTRecord *searchRecord(BTRecord *pRecordPtr) const;
    virtual BTRecord *printArrayRecord() const;
    virtual unsigned short showFragmentation() const;
    virtual bool defragFile();
// -----------------------------------------------------------------------------

    BTRecord *insertRecord();

    int getCounter() const;
    void setCounter(int counter);
    unsigned short getListFreeBlocks() const;
    void setListFreeBlocks(unsigned short pListFreeBlocks);
    ~BTRecordFile();

    BTRecord *getRegistryArray() const;
    void setRegistryArray(BTRecord *pRegistryArray);

    Disk *getDisk() const;
    void setDisk( Disk *pDisk );
    void readRecordFromDiskTest( Disk pDisk, unsigned short pRecordID );
    string sortUserDataFromDisk(std::string pData , Converter *pConversion);   //clasifica los datos en ints, strings, etc...

private:
    BTRecordFileMetadata *_metadataPtr;
    Disk *_disk;
    int _counter;       //llevará la cantidad de registros insertados
    BTRecord *_registryArray;
    unsigned short _listFreeBlocks;

    void insertRecordAUX(BTRecord *pNewRecord, unsigned short pHDer);


};

#endif // BTRECORDFILE_H
