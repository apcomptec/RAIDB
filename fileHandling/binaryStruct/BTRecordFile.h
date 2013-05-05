/*******************************************************************************
 * File: BTRecordFile.h
 * Author: Brallan Aguilar
 * Description: TODO
 * Reference:
 ******************************************************************************/

#ifndef BTRECORDFILE_H
#define BTRECORDFILE_H

#include "fileHandling/binaryStruct/BTRecordFileMetadata.h"
#include "fileHandling/binaryStruct/BTRecord.h"
#include "fileHandling/IRecordFile.h"

class BTRecordFile: public IRecordFile
{
public:

    /**
     * @brief BTRecordFile Constructor
     */
    BTRecordFile();

// -----------------------------------------------------------------------------
// MÉTODOS DE LA INTERFAZ IRECORDFILE
// -----------------------------------------------------------------------------
    virtual BTRecordFileMetadata *getMetadataPtr() const;
    virtual void setMetadata(BTRecordFileMetadata *pMetadataPtr);
    virtual DLL<IRecord *> *getRecordListPtr();
    virtual void setRecordListPtr(DLL<IRecord *> *pListPtr);
    virtual void insertRecordPtr(BTRecord *pRecordPtr) = 0;
    virtual BTRecord *deleteRecordPtr(BTRecord *pRecordPtr);
    virtual BTRecord *searchRecordPtr(BTRecord *pRecordPtr) const;
    virtual unsigned short showFragmentation() const;
    virtual bool defragFile();
// -----------------------------------------------------------------------------

private:

    /**
     * @brief _metadataPtr
     */
    BTRecordFileMetadata *_metadataPtr;

    /**
     * @brief _recordListPtr
     */
    DLL<IRecord *> _recordList;
};

#endif // BTRECORDFILE_H
