/*******************************************************************************
 * File: BTRecordFileMetadata.h
 * Author: Brallan Aguilar
 * Description: TODO
 * Reference:
 ******************************************************************************/

#ifndef BTRECORDFILEMETADATA_H
#define BTRECORDFILEMETADATA_H

#include "fileHandling/IMetadata.h"
#include "fileHandling/IRecordDataType.h"

class BTRecordFileMetadata: public IMetadata
{
public:
    BTRecordFileMetadata();

// -----------------------------------------------------------------------------
// MÉTODOS DE LA INTERFAZ IMETADATA
// -----------------------------------------------------------------------------
    virtual DLL<char> *getRecordStructPtr() const;
    virtual std::string getFileName() const;
    virtual void setFileName(std::string &pFileName);
    virtual unsigned short getFileSize() const;
    virtual void setFileSize(unsigned short &pFileSize);
    virtual unsigned short getBlockSize() const;
    virtual void setBlockSize(unsigned short &pSize);
    virtual std::string getOwner() const;
    virtual void setOwner(std::string &pOwner) = 0;
    virtual DLL<unsigned short> *getFreeBlockListPtr() const;
    virtual void setFreeBlockList(DLL<unsigned short> *pFreeBlockList);
    virtual DLL<unsigned short> *getBlockUsedListPtr() const;
    virtual void setUsedBlockList(DLL<unsigned short> *pBlockUsedList);
    virtual unsigned short *getEOFPtr() const;
    virtual void setEOFPtr(unsigned short *pEOFPtr);
    virtual unsigned short *getBORPtr() const;
    virtual unsigned short setBORPtr(unsigned short *pBORPtr);
// -----------------------------------------------------------------------------

private:

    DLL<char> _recordStruct;
    std::string _fileName;
    unsigned short _fileSize;
    unsigned short _blockSize;
    std::string _owner;
    DLL<IRecordDataType *> _freeBlockList;
    DLL<IRecordDataType *> _usedBlockList;
    unsigned short *_borPtr;
    unsigned short *_eofPtr;
};

#endif // BTRECORDFILEMETADATA_H
