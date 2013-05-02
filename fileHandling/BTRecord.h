/*******************************************************************************
 * File: BTRecord.h
 * Author: Brallan Aguilar
 * Description: Representa un registro en un árbol binario
 * Reference:
 ******************************************************************************/

#ifndef BTRECORD_H
#define BTRECORD_H

#include "ARecord.h"

class BTRecord: public ARecord
{
public:

    /**
     * @brief BTRecord Constructor
     * @param pRegistryStructPtr Puntero constante a una lista constante de
     * datos de registro
     */
    BTRecord(const DLL<IRecordDataType *> * const pRegistryStructPtr);
    virtual bool insert(ARecord *pRegistry);
    virtual bool modify(ARecord *pRegistry);
    virtual ARecord *deleteR(ARecord *pRegistry);

private:

    /**
     * @brief _parentPtr Puntero padre del registro
     * @brief _leftChildPtr Puntero al hijo izquierdo del registro
     * @brief _rightChildPtr Puntero al hijo derecho del registro
     */
    IRecordDataType *_parentPtr, *_leftChildPtr, *_rightChildPtr;

    /**
     * @brief _dataListPtr Lista con los elementos de datos del registro
     */
    DLL<IRecordDataType *> *_dataListPtr;
};

#endif // BTRECORD_H
