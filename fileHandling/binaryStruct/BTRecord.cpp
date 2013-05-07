/*******************************************************************************
 * File: BTRecord.cpp
 * Author: Brallan Aguilar
 * Description: Implementación de BTRecord.h
 * Reference:
 ******************************************************************************/

#include "BTRecord.h"

// -----------------------------------------------------------------------------
// DEFINICIÓN DE CONSTANTES
// -----------------------------------------------------------------------------
const char BTRecord::STRING     = 0;
const char BTRecord::CHAR       = 1;
const char BTRecord::SHORT      = 2;
const char BTRecord::INT        = 3;
const char BTRecord::DOUBLE     = 4;
const char BTRecord::BOOL       = 5;
// -----------------------------------------------------------------------------

BTRecord::BTRecord()
{
}

DLL<IRecordDataType *> *BTRecord::getDataListPtr() const
{
    return _dataListPtr;
}

void BTRecord::setDataList(DLL<IRecordDataType *> *pDataListPtr)
{
    _dataListPtr = pDataListPtr;
}
