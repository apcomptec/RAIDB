/*******************************************************************************
 * File: BTRecord.h
 * Author: Brallan Aguilar
 * Description: Representa un registro en un árbol binario
 * Reference:
 ******************************************************************************/

#ifndef BTRECORD_H
#define BTRECORD_H

#include "dataStructure/DLL.h"
#include "IRecordDataType.h"

class BTRecord
{
public:

// -----------------------------------------------------------------------------
// DEFINICIÓN DE CONSTANTES
// -----------------------------------------------------------------------------
    static const char STRING    = 0;
    static const char CHAR      = 1;
    static const char SHORT     = 2;
    static const char DOUBLE    = 3;
    static const char INT       = 4;
    static const char BOOL      = 5;
// -----------------------------------------------------------------------------

    /**
     * @brief BTRecord Constructor
     * @param pRegistryStructPtr Puntero constante a una lista constante de
     * datos de registro
     */
    BTRecord(const DLL<IRecordDataType *> * const pRegistryStructPtr);
    virtual bool insert(BTRecord *pRegistry);
    virtual bool modify(BTRecord *pRegistry);
    virtual BTRecord *erase(BTRecord *pRegistry);

private:

    /**
     * @brief _parentPtr Puntero padre del registro
     * @brief _leftChildPtr Puntero al hijo izquierdo del registro
     * @brief _rightChildPtr Puntero al hijo derecho del registro
     */
    IRecordDataType *_parentPtr, *_leftChildPtr, *_rightChildPtr;

    /**
     * @brief _registryStructPtr Puntero a una lista doble con las cabeceras de
     * campo del registro.
     */
    const DLL<IRecordDataType *> * const _registryStructPtr;

    /**
     * @brief _dataListPtr Lista con los elementos de datos del registro
     */
    DLL<IRecordDataType *> *_dataListPtr;
};

#endif // BTRECORD_H
