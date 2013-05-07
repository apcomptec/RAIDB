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
    BTRecordFile(BTRecordFileMetadata *pMetadata);

// -----------------------------------------------------------------------------
// MÉTODOS DE LA INTERFAZ IRECORDFILE
// -----------------------------------------------------------------------------
    virtual BTRecordFileMetadata *getMetadata() const;
    virtual void setMetadata(BTRecordFileMetadata *pMetadataPtr);
    virtual DLL<IRecord *> *getRecordList() const;
    virtual void setRecordList(DLL<IRecord *> *pListPtr);
    virtual void insertRecord(DLL<IRecordDataType *> *pListPtr);
    virtual BTRecord *deleteRecord(BTRecord *pRecordPtr);
    virtual BTRecord *searchRecord(BTRecord *pRecordPtr) const;
    virtual unsigned short showFragmentation() const;
    virtual bool defragFile();
// -----------------------------------------------------------------------------

private:

    unsigned short *_index;

    /**
     * @brief _metadataPtr
     */
    BTRecordFileMetadata *_metadataPtr;

    /**
     * @brief _recordListPtr
     */
    DLL<IRecord *> *_recordListPtr;
};

#endif // BTRECORDFILE_H
