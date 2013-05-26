/*******************************************************************************
 * File: IRecordFile.h
 * Author: Brallan Aguilar
 * Description: Interfaz que describe un archivo de registros.
 * Reference:
 ******************************************************************************/

#ifndef IRECORDFILE_H
#define IRECORDFILE_H

#include "IMetadata.h"
#include "IRecord.h"

class IRecordFile
{
public:

    /**
     * @brief getMetadataPtr
     * @return Puntero a metadatos
     */
    virtual IMetadata *getMetadata() const = 0;

    /**
     * @brief setMetadataPtr
     * @param pMetadataPtr Nuevo puntero de metadatos
     */
    virtual void setMetadata(IMetadata *pMetadataPtr) = 0;

    /**
     * @brief getRecordListPtr
     * @return Lista con los registros en el archivo
     */
    virtual DLL<IRecord *> *getRecordList() const = 0;

    /**
     * @brief setRecordListPtr
     * @param pListPtr Nueva lista con registros
     */
    virtual void setRecordList(DLL<IRecord *> *pListPtr) = 0;

    /**
     * @brief insertRecord
     * @param pListPtr Registro que se insertará en el archivo
     */
    virtual IRecord *insertRecord(DLL<IRecordDataType *> *pListPtr) = 0;

    /**
     * @brief deleteRecord
     * @param pRecordPtr Registro a borrar
     * @return Puntero al registro eliminado
     */
//    virtual IRecord *deleteRecord(IRecord *pRecordPtr) = 0;

    /**
     * @brief searchRecordPtr
     * @param pRecordPtr Registro a buscar
     * @return Puntero al registro deseado. Si no se encuentra, retornará
     * nullptr
     */
//    virtual IRecord *searchRecord(IRecord *pRecordPtr) const = 0;

    /**
     * @brief showFragmentation
     * @return Nivel de fragmentación del archivo de registro. Arroja un valor
     * de porcentaje
     */
    virtual unsigned short showFragmentation() const = 0;

    /**
     * @brief defragFile Defragmenta el archivo
     * @return Si la degragmentación se hizo correctamente
     */
    virtual bool defragFile() = 0;
};

#endif // IRECORDFILE_H
