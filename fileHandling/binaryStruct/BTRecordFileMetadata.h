/*******************************************************************************
 * File: BTRecordFileMetadata.h
 * Author: Brallan Aguilar
 * Description: TODO
 * Reference:
 ******************************************************************************/

#ifndef BTRECORDFILEMETADATA_H
#define BTRECORDFILEMETADATA_H

#include "fileHandling/IMetadata.h"

class BTRecordFileMetadata: public IMetadata
{
public:

    /**
     * @brief BTRecordFileMetadata Sobrecarga del constructor
     * @param pFileName Nombre del archivo
     * @param pOwner Dueño del archivo
     * @param pRecordStruct Indica los datos que escogió el usuario que estén
     * presentes en el registro
     */
    BTRecordFileMetadata(const std::string &pFileName,
                         const std::string &pOwner,
                         DLL<IRecordDataType *> *pRecordStruct);

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
    virtual DLL<IRecordDataType *> *getRecordStruct() const;
    virtual unsigned short getRecordSize() const;
    virtual void setRecordSize(const unsigned short &pSize);
    virtual unsigned short getNumberOfRecords() const;
    virtual void setNumberOfRecords(const unsigned short &pNumber);
    virtual std::string getFileName() const;
    virtual void setFileName(const std::string &pFileName);
    virtual unsigned short getFileSize() const;
    virtual std::string getOwner() const;
    virtual void setOwner(const std::string &pOwner);
    virtual unsigned short getFreeBlockList() const;
    virtual void setFreeBlockList(unsigned short pFreeBlockList);
    virtual DLL<unsigned short> *getUsedBlockList() const;
    virtual void setUsedBlockList(DLL<unsigned short> *pBlockUsedList);
    virtual unsigned short getEOF() const;
    virtual void setEOF(const unsigned short &pEOF);
    virtual unsigned short getFirstRecordPos() const;
    virtual void setFirstRecordPos(const unsigned short &pPos);
    virtual void printMetadata() const;
    virtual void printUserRecordStruct() const;

    unsigned short getPointerNextBlock() const; // Dice si posee o no puntero a otro archivo
    void setPointerNextBlock(unsigned short pointerNextBlock);

    // -----------------------------------------------------------------------------


private:

    unsigned short _tamanoMetadata;
    /**
     * @brief _recordStructPtr
     */
    DLL<IRecordDataType *> *_recordStructPtr;

    /**
     * @brief _fileName Nombre del archivo
     * @brief _owner Dueño del archivo
     */
    std::string _fileName, _owner;

    /**
     * @brief _recordSize Tamaño de un registro
     * @brief _numberOfRecords Cantidad de registros presentes en el archivo
     * @brief _fileSize Tamaño del archivo
     * @brief _fr Indica dónde comienza el primer registro. Es una posición
     * dentro del propio archivo equivalente a un desplazamiento en memoria. Se
     * calcula mediante la posición exacta en disco
     * @brief _eof Muestra dónde está el final de archivo
     */
    unsigned short _recordSize, _numberOfRecords, _fileSize, _fr, _eof,
    _freeBlockList, _pointerNextBlock;

    /**
     * @brief _freeBlockList Lista con los bloques libres
     * @brief _usedBlockList Lista con bloques usados
     */
    DLL<unsigned short>  *_usedBlockList;

    virtual unsigned short computeRecordSize();
};

#endif // BTRECORDFILEMETADATA_H
