/*******************************************************************************
 * File: BTRecord.cpp
 * Author: Brallan Aguilar
 * Description: Implementación de BTRecord.h
 * Reference:
 ******************************************************************************/

#include "BTRecord.h"

BTRecord::BTRecord(const DLL<IRecordDataType *> * const pRegistryStructPtr)
    : ARecord(pRegistryStructPtr)
{
    // vacío
}

bool BTRecord::insert(ARecord *pRegistry)
{
    return pRegistry == nullptr;
}

bool BTRecord::modify(ARecord *pRegistry)
{
    return pRegistry == nullptr;
}

ARecord *BTRecord::deleteR(ARecord *pRegistry)
{
    return pRegistry;
}
