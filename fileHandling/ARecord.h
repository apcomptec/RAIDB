/*******************************************************************************
 * File: ARecord.h
 * Author: Brallan Aguilar
 * Description: Clase abstracta que representa los campos de un registro
 * Reference:
 ******************************************************************************/

#ifndef ARECORD_H
#define ARECORD_H

#include "dataStructure/DLL.h"
#include "IRecordDataType.h"
#include "IRecord.h"

class ARecord: public IRecord
{
public:

// -----------------------------------------------------------------------------
// DEFINICIÓN DE CONSTANTES
// -----------------------------------------------------------------------------
    static const char STRING    = 0;
    static const char CHAR      = 1;
    static const char SHORT     = 2;
    static const char DOUBLE    = 3;
    static const char BOOL      = 4;
// -----------------------------------------------------------------------------

    ARecord(const DLL<IRecordDataType *> * const pRegistryStructPtr);

private:

    /**
     * @brief _registryStructPtr Puntero a una lista doble con las cabeceras de
     * campo del registro.
     */
    const DLL<IRecordDataType *> * const _registryStructPtr;
};

#endif // ARECORD_H
