/*******************************************************************************
 * File: IMetadata.h
 * Author: Brallan Aguilar
 * Description: Representa cómo están estructurados los metadatos de un archivo
 * de registro.
 ******************************************************************************/

#ifndef IMETADATA_H
#define IMETADATA_H

#include "dataStructure/DLL.h"
#include "fileHandling/IRecordDataType.h"

class IMetadata
{
public:

    /**
     * @brief getFileName
     * @return Devuelve el nombre del archivo
     */
    virtual std::string getFileName() const = 0;

    /**
     * @brief setFileName Establece el nombre de archivo
     * @param pFileName Nuevo nombre de archivo
     */
    virtual void setFileName(const std::string &pFileName) = 0;

    /**
     * @brief getOwner
     * @return Dueño del archivo
     */
    virtual std::string getOwner() const = 0;

    /**
     * @brief setOwner Establece el dueño del archivo
     * @param pOwner Nuevo dueño
     */
    virtual void setOwner(const std::string &pOwner) = 0;

    /**
     * @brief getFileSize
     * @return Devuelve el tamaño del archivo en bytes
     */
    virtual unsigned short getFileSize() const = 0;

    /**
     * @brief getRecordStruct
     * @return Devuelve cómo estableció el usuario los campos de registro
     */
    virtual DLL<IRecordDataType *> *getRecordStruct() const = 0;

    /**
     * @brief getBlockSize
     * @return Devuelve el tamaño de un registro
     */
    virtual unsigned short getRecordSize() const = 0;

    /**
     * @brief setRecordSize Establece el tamaño de registro
     * @param pSize Nuevo tamaño de registro
     */
    virtual void setRecordSize(const unsigned short &pSize) = 0;

    /**
     * @brief getNumberOfRecords
     * @return Devuelve el número de registros presentes en el registro. En caso
     * de borrarse alguno, debe disminuir su cantidad
     */
    virtual unsigned short getNumberOfRecords() const = 0;

    /**
     * @brief setNumberOfRecords Establece el número de registros
     * @param pNumber Nuevo número de registros
     */
    virtual void setNumberOfRecords(const unsigned short &pNumber) = 0;

    /**
     * @brief getFreeBlockList
     * @return Lista con bloques libres
     */
    virtual unsigned short getFreeBlockList() const = 0;

    /**
     * @brief setFreeBlockList
     * @param pFreeBlockList
     */
    virtual void setFreeBlockList(unsigned short pFreeBlockList) = 0;

    /**
     * @brief getBlockUsedList
     * @return
     */
    virtual DLL<unsigned short> *getUsedBlockList() const = 0;

    /**
     * @brief setBlockUsedList
     * @param pBlockUsedList
     */
    virtual void setUsedBlockList(DLL<unsigned short> *pBlockUsedList) = 0;

    /**
     * @brief getEOF
     * @return Posición relativa del archivo donde se encuentra el fin de este
     * (es independiente de la ubicación del archivo)
     */
    virtual unsigned short getEOF() const = 0;

    /**
     * @brief setEOF
     * @param pEOF
     */
    virtual void setEOF(const unsigned short &pEOF) = 0;

    /**
     * @brief getFirstRecordPos
     * @return Posición relativa al archivo (independientemente de dónde se
     * encuentre el archivo en disco) donde está el primer registro
     */
    virtual unsigned short getFirstRecordPos() const = 0;

    /**
     * @brief setFirstRecordPos Cambia la posición relativa en el archivo del
     * primer registro
     * @param pPos Nueva posición de inicio del primer registo
     */
    virtual void setFirstRecordPos(const unsigned short &pPos) = 0;

    /**
     * @brief printMetadata Imprime la información de los metadatos
     */
    virtual void printMetadata() const = 0;

    /**
     * @brief printUserRecordStruct Imprime cómo el usuario conformó su
     * estructura de datos
     */
    virtual void printUserRecordStruct() const = 0;

private:

    /**
     * @brief computeRecordSize
     * @return Tamaño de un registro
     */
    virtual unsigned short computeRecordSize() = 0;
};

#endif // IMETADATA_H
