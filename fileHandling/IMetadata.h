/*******************************************************************************
 * File: IMetadata.h
 * Author: Brallan Aguilar
 * Description: TODO
 * Reference:
 ******************************************************************************/

#ifndef IMETADATA_H
#define IMETADATA_H

#include "dataStructure/DLL.h"

class IMetadata
{
public:

    /**
     * @brief getRecordStruct
     * @return
     */
    virtual DLL<char> *getRecordStructPtr() const = 0;

    /**
     * @brief getFileName
     * @return
     */
    virtual std::string getFileName() const = 0;

    /**
     * @brief setFileName
     * @param pFileName
     */
    virtual void setFileName(std::string &pFileName) = 0;

    /**
     * @brief getFileSize
     * @return
     */
    virtual unsigned short getFileSize() const = 0;

    /**
     * @brief setFileSize
     * @param pFileSize
     */
    virtual void setFileSize(unsigned short &pFileSize) = 0;

    /**
     * @brief getBlockSize
     * @return
     */
    virtual unsigned short getBlockSize() const = 0;

    /**
     * @brief setBlockSize
     * @param pSize
     */
    virtual void setBlockSize(unsigned short &pSize) = 0;

    /**
     * @brief getOwner
     * @return
     */
    virtual std::string getOwner() const = 0;

    /**
     * @brief setOwner
     * @param pOwner
     */
    virtual void setOwner(std::string &pOwner) = 0;

    /**
     * @brief getFreeBlockList
     * @return
     */
    virtual DLL<unsigned short> *getFreeBlockListPtr() const = 0;

    /**
     * @brief setFreeBlockList
     * @param pFreeBlockList
     */
    virtual void setFreeBlockList(DLL<unsigned short> *pFreeBlockList) = 0;

    /**
     * @brief getBlockUsedList
     * @return
     */
    virtual DLL<unsigned short> *getUsedBlockListPtr() const = 0;

    /**
     * @brief setBlockUsedList
     * @param pBlockUsedList
     */
    virtual void setUsedBlockList(DLL<unsigned short> *pBlockUsedList) = 0;

    /**
     * @brief getEOFPtr
     * @return
     */
    virtual unsigned short *getEOFPtr() const = 0;

    /**
     * @brief setEOFPtr
     * @param pEOFPtr
     */
    virtual void setEOFPtr(unsigned short *pEOFPtr) = 0;

    /**
     * @brief getBORPtr
     * @return
     */
    virtual unsigned short *getBORPtr() const = 0;

    /**
     * @brief setBORPtr
     * @param pBORPtr
     */
    virtual void setBORPtr(unsigned short *pBORPtr) = 0;
};

#endif // IMETADATA_H
