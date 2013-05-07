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
    virtual void setDataList(DLL<IRecordDataType *> *pListPtr) = 0;

    virtual unsigned short *getIndex() const = 0;
    virtual void setIndex(unsigned short *pIndexPtr) = 0;
};

#endif // IRECORD_H
