/*******************************************************************************
 * File: BTRecord.cpp
 * Author: Brallan Aguilar
 * Description: Implementación de BTRecord.h
 * Reference:
 ******************************************************************************/

#include "BTRecord.h"

BTRecord::BTRecord(const DLL<IRecordDataType *> * const pRegistryStructPtr)
    : _registryStructPtr(pRegistryStructPtr)
{
    // vacío
}

bool BTRecord::insert(BTRecord *pRegistry)
{
    return pRegistry == nullptr;
}

bool BTRecord::modify(BTRecord *pRegistry)
{
    return pRegistry == nullptr;
}

BTRecord *BTRecord::erase(BTRecord *pRegistry)
{
    return pRegistry;
}
