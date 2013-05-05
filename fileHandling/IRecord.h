/*******************************************************************************
 * File: IRecord.h
 * Author: Brallan Aguilar
 * Description: Interfaz de un registro. Representa uno solo.
 * Reference:
 ******************************************************************************/

#ifndef IRECORD_H
#define IRECORD_H

#include "dataStructure/DLL.h"
#include "IRecordDataType.h"

class IRecord
{
public:

    /**
     * @brief getDataListPtr
     * @return Puntero a la lista de datos del registro (dados por el usuario)
     */
    virtual DLL<IRecordDataType *> *getDataListPtr() const = 0;

    /**
     * @brief setDataListPtr
     * @param pDataListPtr Nueva lista de datos de registro (dados por el
     * usuario)
     */
    virtual void setDataList(DLL<IRecordDataType *> *pListPtr) const = 0;

    /**
     * @brief getRecordStructPtr
     * @return Puntero a la lista en cómo se estructura el registro (cada campo
     * del registro, cómo está organizado)
     */
    virtual DLL<char> *getRecordStructPtr() const = 0;

    /**
     * @brief setRecordStructPtr
     * @param pListPtr Nuevo puntero a la lista de estructura del registro
     */
    virtual void setRecordStruct(DLL<char> *pListPtr) const = 0;
};

#endif // IRECORD_H
