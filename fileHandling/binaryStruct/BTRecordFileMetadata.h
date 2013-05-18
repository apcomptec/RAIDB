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

    /**
     * @brief BTRecordFileMetadata Sobrecarga del constructor. Este se encarga
     * de solicitar la información mediante consola
     */
    BTRecordFileMetadata();

    /**
     * @brief BTRecordFileMetadata Sobrecarga del constructor
     * @param pRecordStructPtr
     * @param pFileName
     * @param pOwner
     */
    BTRecordFileMetadata(DLL<char> *pRecordStructPtr,
                         const std::string &pFileName,
                         const std::string &pOwner);

// -----------------------------------------------------------------------------
// PROTOTIPO DE CONSTANTES
// -----------------------------------------------------------------------------
    static const char STRING;
    static const char CHAR;
    static const char SHORT;
    static const char INT;
    static const char DOUBLE;
    static const char BOOL;
// -----------------------------------------------------------------------------

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
    virtual void setOwner(std::string &pOwner);
    virtual DLL<unsigned short> *getFreeBlockListPtr() const;
    virtual void setFreeBlockList(DLL<unsigned short> *pFreeBlockList);
    virtual DLL<unsigned short> *getUsedBlockListPtr() const;
    virtual void setUsedBlockList(DLL<unsigned short> *pBlockUsedList);
    virtual unsigned short *getEOFPtr() const;
    virtual void setEOFPtr(unsigned short *pEOFPtr);
    virtual unsigned short *getBORPtr() const;
    virtual void setBORPtr(unsigned short *pBORPtr);
// -----------------------------------------------------------------------------

private:

    DLL<char> *_recordStructPtr;
    std::string _fileName;
    std::string _owner;
    unsigned short _fileSize;
    unsigned short _blockSize;
    DLL<unsigned short> *_freeBlockList;
    DLL<unsigned short> *_usedBlockList;
    unsigned short *_borPtr;
    unsigned short *_eofPtr;

    /**
     * @brief constructMetadata Construye los metadatos solicitandolos por
     * consola
     */
    void constructMetadata();
};

#endif // BTRECORDFILEMETADATA_H
